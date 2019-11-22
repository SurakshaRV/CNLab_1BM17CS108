#include<iostream>
#include<unistd.h>
#include<stdlib.h>
#define buckSize 512
using namespace std;
void bktIp(int a, int b);
int main()
{
int op, pktSize;
cout<<"Enter output rate: ";
cin>>op;
for(int i=1;i<=5;i++){
usleep(rand()%1000);
pktSize=rand()%1000;
cout<<"\n Packet no. "<<i<<"\t Packet size = "<<pktSize;
bktIp(pktSize,op);
}
return 0;
}
void bktIp(int a, int b){
if(a>buckSize)
cout<<"\n\tBuckt overflow";
else{
usleep(500);
while(a>b){
cout<<"\n\t"<<b<<"bytes outputteed";
a-=b;
usleep(500);
}
if(a>0)
cout<<"\n\t Last " <<a<< " bytes sent\t";
cout<<"\n\t Bucket ouput successful\n";
}
}
