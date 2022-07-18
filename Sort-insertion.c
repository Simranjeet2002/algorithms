//insertion short
#include<stdio.h>

int main()
{
    int n,a[10],i,j,key;
    
    printf("enter the no of elements in array");
    scanf("%d",&n);
    
    printf("enter the elements of array");
    for(i=0;i<n;i++)
    {
    scanf("%d",&a[i]);
    }
    
    for(i=1;i<n;i++)
    {
      
      for(j=i;j>=0;j--)
      {
        if(a[j]<a[j-1])
       {
        key=a[j];
          a[j]=a[j-1];
          a[j-1]=key;
        }
      }
    }
    
    printf("shoted array is");
    for(i=0;i<n;i++)
    {
    printf("%d\t",a[i]);
    }
    
     return 0;
}