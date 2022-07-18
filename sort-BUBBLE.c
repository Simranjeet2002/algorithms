//bubble short
#include<stdio.h>

int main()
{
    int n,a[10],i,j,key,flag;
    
    printf("enter the no of elements in array");
    scanf("%d",&n);
    
    printf("enter the elements of array");
    for(i=0;i<n;i++)
    {
    scanf("%d",&a[i]);
    }
    
    for(i=0;i<n-1;i++)
    {
      //flag=0;
      for(j=0;j<n-i-1;j++)
      {
        if(a[j]>a[j+1])
        {
          key=a[j+1];
          a[j+1]=a[j];
          a[j]=key;
          flag=1;
        }
      }
       /*if(flag==0)
          {
           break;
           }*/
    }
    
    printf("shoted array is");
    for(i=0;i<n;i++)
    {
    printf("%d\t",a[i]);
    }
    
     return 0;
}