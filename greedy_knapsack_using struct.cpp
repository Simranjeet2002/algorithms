#include<iostream>
#include<stdio.h>
using namespace std;
struct knap
{
    int ino;
    float weight;
    float profit;
    float ratio;
    float x;
    
};
void knapsack(struct knap kn[],int n,float m,float *tp)
{
    for(int i=1;i<=n;i++)
    {
         if(m<kn[i].weight)
          {
              kn[i].x=m/kn[i].weight;
              *tp=*tp+(kn[i].profit*kn[i].x);
              break;
          }
        
        kn[i].x=1.0;
        *tp=*tp+kn[i].profit;
        m=m-kn[i].weight;     
    }
    
}
int main()
{
    struct knap kn[20],temp;
    int n,i,j;
    float m,tp;
    printf("\nENTER THE TOTAL NO OF OBJECTS:");
    scanf("%d",&n);
    
    printf("\nENTER WEIGHT AND PROFIT FOR %d ITEMS:-\n",n);
    for( i=1;i<=n;i++)
    {
    printf("\n\t\tITEM %d:-\n",i);
    printf("PROFIT: ");
    scanf("%f",&kn[i].profit);
    printf("WEIGHT: ");
    scanf("%f",&kn[i].weight);
     kn[i].ino=i;
     kn[i].x=0.0;
     kn[i].ratio=(kn[i].profit/kn[i].weight);    
    }
    
    printf("\nENTER THE CAPACITY OF KNAPSACK:  ");
    scanf("%f",&m);
    
    for( i=1;i<n;i++)
    {     
        for( j=1;j<=n-i;j++)
        {
            if(kn[j].ratio<kn[j+1].ratio)
            {
                temp=kn[j];
                kn[j]=kn[j+1];
                kn[j+1]=temp;
            }
        }
    }
    knapsack(kn,n,m,&tp);
    
    printf("\n FOR KNAPSACK:-");
    	for (i = 1; i<=n; i++)
		printf("\nITEM: %d\nAMOUNT CONSIDERED:%f ",kn[i].ino, kn[i].x);
	
  printf("\n\nTOTAL PROFIT: %f",tp);
    
    return 0;
}