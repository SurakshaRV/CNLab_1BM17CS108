#include<stdio.h> #include<unistd.h> #include<sys/stat.h> #include<fcntl.h> #include<string.h> #define FIFO1 "fifo1" #define FIFO2 "fifo2" #define PERMS 0666 char fname[512];
int main( ) {
 int readfd, writefd, fd;
 ssize_t n;
 char buff[512];
 char end[5]="end";
 int cmp = 0;
 int le;
 char st[80];
writefd=open(FIFO1, O_WRONLY, 0);
readfd =open(FIFO2, O_RDONLY, 0);
printf("Connected..\n");
while(1) {
   printf("Enter thr string " );
   fgets(st,sizeof(st),stdin);
   le = strlen(st); st[le-1]='\0'; cmp = strcmp(st,"end");
  if(cmp==0) { write(writefd,st,strlen(st)+1);
    printf("end");
    break;
  } else {
  write(writefd,st,strlen(st)+1); printf("%s\n",st);
  }
}
printf("Waiting for reply from server ......\n");  
  while((n=read(readfd,buff,512))>0)    {
        write(1,buff,n);    }
         printf("\n");
          close(readfd); unlink(FIFO1);
          close(writefd); unlink(FIFO2); }
