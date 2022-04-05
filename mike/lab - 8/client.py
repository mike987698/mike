import socket

c = socket.socket()
print("Client Socket Created \n")

c.connect(('localhost' , 9999))

while True:
    print(c.recv(1024).decode())