from fileinput import filename
import socket
 
c = socket.socket()
print("Socket Created Successfully")

host = input(str("please enter the address you want the file to send to :\n"))
c.connect((host , 9999))
print("Connected Succesfully with the server \n")
filename = input(str("please enter the name of the file :\n"))
file = open(filename , 'wb')
file_data = c.recv(1024)
file.write(file_data)
file.close()
print("file has been recieved succesfully \n")