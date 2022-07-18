//linearsearch
#include<stdio.h>

int main()
{
    int i,n,a[10],e,flag=0;
    printf("enter the no of elements in array");
    scanf("%d",&n);
    
    printf("enter the elements of array");
    for(i=0;i<n;i++)
    {
    scanf("%d",&a[i]);
    }
    
    printf("enter the ele u want to find");
    scanf("%d",&e);
    
    for(i=0; i<n ;i++)
    {
        if(e==a[i])
        {
        flag=1 ;
        printf("element found at index %d ",i);
        break;
        }
    }    
    if(flag==0)
    {
    printf("element not found");
   } 
    
    
    return 0;
}