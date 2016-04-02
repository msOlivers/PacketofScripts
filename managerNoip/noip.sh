#!/bin/sh
# REFERENCIA: http://www.savant.com.br/index.php/artigos/tutoriais/26
#
# noip2        Registra o endereco IP nos DNS do site noip.com
# chkconfig: 2345 20 80
# description: Register IP host on DNS servers from noip.com
#
### BEGIN INIT INFO
# Provides:          noip2
# Required-Start:    noip2
# Required-Stop:     noip2
# Default-Start:     S
# Default-Stop:      0 6
# Short-Description: Register IP host on no-ip.org named domain
### END INIT INFO

# RedHat style - descomente a linha a seguir se você está usando
# RH/Fedora/CentOS
#. /etc/rc.d/init.d/functions   # uncomment/modify for your killproc

# Debian style - descomente a linha a seguir se você está usando
# Debian/Ubuntu
. /lib/lsb/init-functions       # uncomment/modify for your killproc

# Colors - Edited by msOlivers
# Reset
reset="\033[0m"       # Text Reset
# Regular Colors
Black="\033[0;30m"        # Black
Red="\033[0;31m"          # Red
Green="\033[0;32m"        # Green
Yellow="\033[0;33m"       # Yellow
Blue="\033[0;34m"         # Blue
Purple="\033[0;35m"       # Purple
Cyan="\033[0;36m"         # Cyan
White="\033[0;37m"        # White
case "$1" in

   start) echo "[${Green} ok ${reset}] Starting noip2"
          /usr/local/bin/noip2
          ;;

   stop)  echo "[${Green} ok ${reset}] Stopping down noip2"
	  #killproc -TERM /usr/local/bin/noip2
	  kill `pgrep noip2` # Part kill proc add by msOlivers
          ;;
   # Part status add by msOlivers
   status) 
	 status_of_proc /usr/local/bin/noip2
          ;;

   *)     echo "${Blue}Usage:${reset} ${Green}$0 ${reset}${Yellow}{start|stop|status}"
          exit 1
esac
exit 0
