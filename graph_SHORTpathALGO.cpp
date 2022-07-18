#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void shortestpath(int v,int n,float cost[][20],float dist[])
{
    int s[20],w,u,i,j;
    float min;

    for(i=1; i<=n; i++)
    {
        s[i]=0;
        dist[i]=cost[v][i];
    }
    s[v]=1;
    dist[v]=0.0;
    for(i=2; i<=n; i++)
    {
        min=9999.0;
        for(j=1; j<=n; j++)
        {
            if(dist[j]!=9999.0&&s[j]!=1&&min>dist[j])
            {
                min=dist[j];
                u=j;
            }
        }
        s[u]=1;
        for(j=1; j<=n; j++)
        {
            if(cost[u][j]!=9999.0&&s[j]!=1&&dist[j]>(dist[u]+cost[u][j]))
            {
                dist[j]=dist[u]+cost[u][j];
            }
        }

    }


}
int main()
{
    int n,e,i,j,k,v=1;
    float cost[20][20],dist[20];
    printf("\nENTER THE NO OF NODES : ");
    scanf("%d",&n);
    printf("\nENTER THE NO OF EDGES : ");
    scanf("%d",&e);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(i==j)
                cost[i][j]=0.0;
            else
                cost[i][j]=9999.0;
        }
    }

    for(i=1; i<=e; i++)
    {
        printf("ENTER j and k vertex btw which edge is presen\n ");
        scanf("%d %d",&j,&k);
        printf("ENTER COST FOR EDGE(%d,%d):",j,k);
        scanf("%f",&cost[j][k]);
    }
    printf("\n\tCOST ADJACENCY MATRIX IS\n");
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
            printf("%f ",cost[i][j]);
        printf("\n");
    }
    shortestpath(v,n,cost,dist);

    printf("\nSHORTEST DISTANCE FROM VERTEX %d :\n",v);
    for(i=1; i<=n; i++)
    {
        printf("TO VERTEX %d = %f\n",i,dist[i]);
    }
}