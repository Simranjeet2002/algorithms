#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;
struct queue
{
    int r=-1,f=-1,s=20;
    int que[20];
};
int isempty(struct queue* q)
{
    if(q->f==-1&&q->r==-1)
        return 1;
    return 0;
}
int isfull(struct queue* q)
{
    if(q->r==(q->s)-1)
        return 1;
    return 0;
}
void enqueue(struct queue* q,int val)
{
    if(isfull(q))
        printf("\nQUEUE OVERFLOW \n");
    else if(q->f==-1&&q->r==-1)
    {
        q->f++;
        q->que[++(q->r)]=val;
    }
    else
        q->que[++(q->r)]=val;
}
int dequeue(struct queue* q)
{
    int val;
    if(isempty(q))
    {
        printf("\nQUEUE UNDERFLOW\n");
        val=-1;
    }
    else if(q->f==q->r)
    {
        val=q->que[q->f];
        q->f=q->r=-1;
    }
    else
    {
        val=q->que[(q->f)++];
    }
    return val;

}
void display(struct queue *q)
{
    if(isempty(q))
        printf("\nQUEUE UNDERFLOW\n");
    else
    {
        printf("\nELEMENTS OF QUEUE ARE:\n");
        for(int i=q->f; i<=q->r; i++)
            printf("%d  ",q->que[i]);
    }
}
void BFS(int v,int n,int a[][20],struct queue* q,int visited[])
{
    int i,u=v;
    visited[u]=1;
    printf("%d ",u);
    while(1)
    {
        for(i=1; i<=n; i++)
        {
            
            if(a[u][i]==1&&visited[i]==0)
            {
                enqueue(q,i);
                visited[i]=1;
                printf("%d ",i);
            }

        }
        if(isempty(q))
            return;
        u=dequeue(q);
    }
}
void BFT(int a[][20],int n,struct queue *q)
{
    int visited[20],i;
    for( i=1;i<=n;i++)
    visited[i]=0;
    for( i=1; i<=n; i++)
    {
        if(visited[i]==0)
            BFS(i,n,a,q,visited);
    }
}
void DFS(int v,int n,int a[][20],int visited[])
{
    int u=v,i;
    visited[u]=1;
    printf("%d ",u);
    for(i=1;i<=n;i++)
    {
        if(a[u][i]==1&&visited[i]==0)
        DFS(i,n,a,visited);
    }
}
void DFT(int a[][20],int n)
{
    int visited[20],i;
    for( i=1;i<=n;i++)
    visited[i]=0;
    for( i=1; i<=n; i++)
    {
        if(visited[i]==0)
            DFS(i,n,a,visited);
    }
}
int main()
{
    struct queue q;
    int n,e,i,j,k,a[20][20]= {0};
    printf("Enter the no of nodes and edges:\n");
    scanf("%d %d",&n,&e);
    for(i=1; i<=e; i++)
    {
        printf("\nENTER node j and k btw which edge is present:\n");
        scanf("%d %d",&j,&k);
        a[j][k]=a[k][j]=1;
    }
    printf("\n\tADJANCY MATRIX WILL BE:\n\t");
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
            printf("%d\t", a[i][j]);
        printf("\n\t");
    }
    printf("\nBFT TRAVERSAL IS:\n");
    BFT(a,n,&q);
    printf("\nDFT TRAVERSAL IS:\n");
    DFT(a,n);
    return 0;
}