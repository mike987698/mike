import socket
import time

s = socket.socket()
print("server side scoket created \n")

s.bind(('localhost' , 9999))

s.listen(5)
print("Waiting for the connections")

while True:
    c , addr = s.accept()
    print("Connected With " , addr)
    sendInterval = 1000
    while True:
        data = "#" * 1500
        c.send(bytes(data , 'utf-8'))
        time.sleep(sendInterval // 1000)