#include<iostream>
#include<stdio.h>
using namespace std;
void knapsack(float profit[],float weight[],float x[],int n,float m,float *tp)
{
    for(int i=1; i<=n; i++)
    {
        if(m<weight[i])
        {
            x[i]=m/weight[i];
            *tp=*tp+(profit[i]*x[i]);
            break;
        }

        x[i]=1.0;
        *tp=*tp+profit[i];
        m=m-weight[i];
    }

}
void swap(float* x,float* y)
{
    float temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
int main()
{
    float profit[20],weight[20],ratio[20],x[20];
    int n,i,j,ino[20];
    float m,tp;
    printf("\nENTER THE TOTAL NO OF OBJECTS:");
    scanf("%d",&n);

    printf("\nENTER WEIGHT AND PROFIT FOR %d ITEMS:-\n",n);
    for( i=1; i<=n; i++)
    {
        ino[i]=i;
        x[i]=0.0;
        printf("\n\t\tITEM %d:-\n",i);
        printf("PROFIT: ");
        scanf("%f",&profit[i]);
        printf("WEIGHT: ");
        scanf("%f",&weight[i]);
        ratio[i]=profit[i]/weight[i];
    }

    printf("\nENTER THE CAPACITY OF KNAPSACK:  ");
    scanf("%f",&m);

    for( i=1; i<n; i++)
    {
        for( j=1; j<=n-i; j++)
        {
            if(ratio[j]<ratio[j+1])
            {
                int k=ino[j];
                ino[j]=ino[j+1];
                ino[j+1]=k;
                swap(&profit[j],&profit[j+1]);
                swap(&weight[j],&weight[j+1]);
                swap(&ratio[j],&ratio[j+1]);
                swap(&x[j],&x[j+1]);
            }
        }
    }
    knapsack(profit,weight,x,n,m,&tp);

    printf("\n FOR KNAPSACK:-");
    for (i = 1; i<=n; i++)
        printf("\nITEM: %d\nAMOUNT CONSIDERED:%f ",ino[i], x[i]);

    printf("\n\nTOTAL PROFIT: %f",tp);

    return 0;
}