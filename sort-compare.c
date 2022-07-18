
#include<stdio.h>
void bubblesort(int n,int a[]);
void selectionsort(int n,int a[]);
void insertionsort(int n,int a[]);
int main()
{
    int n,a[10],i,j;
    
    printf("enter the no of elements in array");
    scanf("%d",&n);
    
    printf("enter the elements of array");
    for(i=0;i<n;i++)
    {
    scanf("%d",&a[i]);
    }
      bubblesort( n, a); 
    selectionsort( n, a);
    insertionsort(n,a);
    return 0;
 } 
    void bubblesort(int n,int a[])
    {
    int i,j,key,swap=0,iter =0,comp=0,flag;
    for(i=0;i<n-1;i++)
    {
       iter++;
       flag=0;
      for(j=0;j<n-i-1;j++)
      {
        comp++;
        if(a[j]>a[j+1])
        {
          key=a[j+1];
          a[j+1]=a[j];
          a[j]=key;
          flag=1;
         swap++;
        }
      }
       if(flag==0)
          {
           break;
           }
    }
    printf("in buuble short\n");
   printf("no of iterations=%d\n",iter);
   printf("no of comparison=%d\n",comp);
   printf("no of swap=%d\n",swap);
   } 
   void insertionsort(int n,int a[])
{   
   int i,j ,flag,key,iter=0,comp=0,swap=0;
    for(i=1;i<n;i++)
    {
    flag=0;
      iter++;
       flag=0;
      for(j=i;j>=0;j--)
      {
       comp++;
        if(a[j]<a[j-1])
       {
        key=a[j];
          a[j]=a[j-1];
          a[j-1]=key;
         swap++;
        flag=1;
        
        }
      }
    if(flag==0)
          {
           break;
           }
    }printf("in insertion short\n");
   printf("no of iterations=%d\n",iter);
   printf("no of comparison=%d\n",comp);
   printf("no of swap=%d\n",swap);
}
    selectionsort(int n,int a[])
    {
    int i,flag,j,key,min,iter=0,comp=0,swap=0;
min=0;
    for(i=0;i<n;i++)
    {  flag=0;
      iter++;
      for(j=i+1;j<n;j++)
      {
    comp++;
        if(a[j]<a[min])
        {
         min=j;
        flag=1;
         }
        if(flag==0)
          {
           break;
           }
       } 
        key=a[min];
          a[min]=a[i];
          a[i]=key;
        swap++;
    }
    printf("in selection short\n");
   printf("no of iterations=%d\n",iter);
   printf("no of comparison=%d\n",comp);
   printf("no of swap=%d\n",swap);
}