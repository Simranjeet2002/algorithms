//selection short
#include<stdio.h>

int main()
{
    int n,a[10],i,j,key,min;
    
    printf("enter the no of elements in array");
    scanf("%d",&n);
    
    printf("enter the elements of array");
    for(i=0;i<n;i++)
    {
    scanf("%d",&a[i]);
    }
    min=0;
    for(i=0;i<n;i++)
    {
      
      for(j=i+1;j<n;j++)
      {
        if(a[j]<a[min])
        {
         min=j;
         }
       } 
        key=a[min];
          a[min]=a[i];
          a[i]=key;
    }
    
    printf("shoted array is");
    for(i=0;i<n;i++)
    {
    printf("%d\t",a[i]);
    }
    
     return 0;
}