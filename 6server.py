from socket import *
st = ""
serverPort = 12000
serverSocket = socket(AF_INET,SOCK_DGRAM)
serverSocket.bind(("127.0.0.1",serverPort))
files = ['file1.txt','file2.txt','test.txt']
print("server is ready to receive")
while 1:
    sentence,clientAddress = serverSocket.recvfrom(2048)
    for i in files:
        fil = open(i,"r")
        y = fil.read().replace("."," ").replace(","," ")
        x = y.strip().split()
        p = sentence.decode('utf-8')
        if p in x:
            st = st+str(i)+" "
        fil.close()
    if(len(st)!=0):
        serverSocket.sendto(bytes(st,"utf-8"),clientAddress)
    else:
        serverSocket.sendto(bytes("Not found","utf-8"),clientAddress)
    print("sent")
    break
