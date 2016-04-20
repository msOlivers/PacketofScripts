# PacketofScripts/webDelivery

## web_deliveryBuild
Edit the file with your web delivery.rc configurations
in the following lines, Line 5 and Line 6

## web_deliveryBuild.c
to compile your exploit to use the exe web_deliveryBuild.c edit as in video

# Windows
# Donwload gcc-4.9-win32 in http://sourceforge.net/projects/mingw-w64/files/latest/download
$ gcc web_deliveryBuild.c -o web_deliveryBuild.exe -lws2_32
# Linux 
$ apt-get install mingw32
$ i586-mingw32msvc-gcc web_deliveryBuild.c -o web_deliveryBuild.exe -lws2_32
