from socket import *
serverName=gethostname()
serverPort=12000
serverSocket=socket(AF_INET,SOCK_STREAM)
serverSocket.bind((serverName,serverPort))
serverSocket.listen(1)
print("The Server is ready to recieve")
while(1):
    count=0
    conn,addr=serverSocket.accept()
    file2=conn.recv(1024).decode()
    list1=[]
    list1=file2.split()
    file=open(list1[0],"r", encoding='utf8', errors='ignore')
    words=file.read(1024)
    list2=[]
    list2=words.split()
    for i in list2:
        if list1[1]==i :#or list1[i] +'\n'==i:
            count+=1
    print(count)
    conn.send(str(count).encode('utf8'))
    file.close()
conn.close()
