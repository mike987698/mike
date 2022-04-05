import socket

s = socket.socket()
print('Socket created')

s.bind(('localhost', 9999))

s.listen(1)
print('Waiting for Connections')

while True :
    c,addr =s.accept()
    print("Connected with ",addr)
    paragraph=c.recv(1024).decode()
    sentences = paragraph.split('.')
    #print(len(sentences))
    words=[]
    for sentence in sentences :
        temp=sentence.split(' ')
        words.extend(temp)
    charcount=0
    for word in words :
        charcount=charcount+len(word)
    
    ans="sentences :"+str(len(sentences))+" words :"+str(len(words))+" characters :"+str(charcount)
    c.send(bytes(ans, 'utf-8'))

    c.close()