import socket
host = socket.gethostname()
port = 12397 

c = socket.socket()

c.connect(('172.30.14.235', 3000))

with open('paragraph.txt', 'r') as ip:
    paragraph = ip.read()
c.send(bytes(paragraph, 'utf-8'))

print(c.recv(1024).decode())

c.close()
