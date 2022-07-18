//binarysearch 
#include<stdio.h>

int main()
{
    int e,n,a[10],i,j,key,min,mid,flag=0,lb,ub;
    
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
    
   /* printf("shoted array is");
    for(i=0;i<n;i++)
    {
    printf("%d\t",a[i]);
    }*/
    
    printf("enter the element u want to found =");
    scanf("%d",&e);
    lb=0;
    ub=n-1;
    while(lb<=ub)
    {
      mid=ub+lb/2;
      
      if(a[mid]==e)
       {
       printf("elementfound ");
       flag=1 ;
      break;
       }
     else if(e>a[mid])
       {
      lb=mid+1;
       }
     else if(e<a[mid])
        {
     ub= mid-1;
        }
    }
    if(flag==0)
    {
    printf("element not found");
    }
     return 0;
}