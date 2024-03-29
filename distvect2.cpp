#include<bits/stdc++.h>
using namespace std;
struct node
{
    unsigned dist[20];
    unsigned from[20];
}rt[10];
int main()
{
    int costmat[20][20];
    int nodes,i,j,k,count=0;
    cout<<"\nEnter the number of nodes : ";
    cin>>nodes;//Enter the nodes
    cout<<"\nEnter the cost matrix :\nEnter 99 if no direct edge and 1 if adjacent:\n";
    for(i=0;i<nodes;i++)
    {
        for(j=0;j<nodes;j++)
        {
            cin>>costmat[i][j];
            //costmat[i][i]=0;
            rt[i].dist[j]=costmat[i][j];//initialise the distance equal to cost matrix
            rt[i].from[j]=j;
        }
    }
        do
        {
            count=0;
            for(i=0;i<nodes;i++)//We choose arbitary vertex k and we calculate the direct distance from the node i to k using the cost matrix
            //and add the distance from k to node j
            for(j=0;j<nodes;j++)
            for(k=0;k<nodes;k++)
                if(rt[i].dist[j]>costmat[i][k]+rt[k].dist[j])
                {//We calculate the minimum distance
                    rt[i].dist[j]=rt[i].dist[k]+rt[k].dist[j];
                    rt[i].from[j]=k;
                    count++;
                }
        }while(count!=0);
        for(i=0;i<nodes;i++)
        {
            cout<<"\n\n For router \n"<<i+1;
            for(j=0;j<nodes;j++)
            {
                cout<<"\t\nnode "<<j+1<<" via "<<rt[i].from[j]+1<<" Distance "<<rt[i].dist[j]<<" ";
            }
        }
    cout<<"\n\n";
    return 0;
}
