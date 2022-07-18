#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<cmath>
int place(int r,int c,int x[])
{
    int i;
    for(i=1; i<r; i++)
    {
        if(x[i]==c||(abs(x[i]-c)==abs(i-r)))
            return 0;
    }
    return 1;
}
void NQueen(int r,int n,int x[])
{
    int c,i;
    for(c=1; c<=n; c++)
    {
        if(place(r,c,x))
        {
            x[r]=c;
            // printf("x: %d",x[r]);
            if(r==n)
            {
                printf("{");
                for(i=1; i<=n; i++) 
                    printf(" %d",x[i]);
                printf(" }\n");
            }
            else
                NQueen(r+1,n,x);
        }
    }
}
int main()
{
    int n,i,j;
    int x[50];
    printf("\nENTER THE NO OF QUEENS: ");
    scanf("%d",&n);
    printf("\nSOLUTIONs ARE :\n");
    NQueen(1,n,x);
}