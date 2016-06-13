#!/usr/bin/python
# -*- coding: utf-8 -*-
def IP():
	from urllib2 import urlopen
	from re import findall

	lists = [
	"http://www.get-ip.me/",
	"http://checkip.dyndns.org/",
	"http://whatsmyip.net/",
	"http://mxtoolbox.com/WhatIsMyIP/",
	]

	for x in lists:
		try:
			data = urlopen(x, timeout=2).read()
			grab = findall('([0-9]+\.[0-9]+\.[0-9]+\.[0-9]+)', data)
			ip = grab[0]
			break
		except:
			pass

	if len(ip) < 0:
		return "EXTERNAL IP Not founded."
	else:
		nat = "IP EXTERNAL : %s\t" %   ip
		localIP( nat)

def localIP( natip):
	#http://stackoverflow.com/questions/166506/finding-local-ip-addresses-using-pythons-stdlib
	import socket
	print "\n"+natip
	try:
		print "IP LOCAL    : %s\t" % ([l for l in ([ip for ip in socket.gethostbyname_ex(socket.gethostname())[2] if not ip.startswith("127.")][:1], [[(s.connect(('8.8.8.8', 80)), s.getsockname()[0], s.close()) for s in [socket.socket(socket.AF_INET, socket.SOCK_DGRAM)]][0][1]]) if l][0][0])
	except:
		print "Local IP Not founded."
	print ""

print IP()
