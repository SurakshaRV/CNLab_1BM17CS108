from socket import *
serverName=gethostname()
serverPort=12000
clientSocket=socket(AF_INET,SOCK_STREAM)
clientSocket.connect((serverName,serverPort))
file1=input("Enter file name and the word : ")
clientSocket.send(file1.encode())
wordcount=clientSocket.recv(1024).decode('utf8')
print(wordcount)
clientSocket.close() 
