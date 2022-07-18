#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void insert_tree(int a[],int n);
int delMax(int a[],int *n,int *x);
int main()
{
    int n,i,x,a[20];
    printf("enter the size of array");
    scanf("%d",&n);
    printf("enter the elements in array");
    for( i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        insert_tree(a,i);
    }

    printf("array is  ");
    for(int i=1; i<=n; i++)
        printf("%d ",a[i]);

    delMax(a,&n,&x);

    printf("array after delition is ");
    for(int i=1; i<=n; i++)
        printf("%d ",a[i]);
    return 0;
}
int delMax(int a[],int *n,int *x)
{
    if(*n==0)
        return 0;
    *x=a[1];
    a[1]=a[*n];
    *n--;
    adjust(a,1,*n);
    return 1;
}
void adjust(int a[],int i,int n)
{
    int item,j;
    item=a[i];
    j=2*i;
    while(j<=n)
    {
        if(j<n&&a[j]<a[j+1])
            j=j+1;
        if(item>a[j])
            break;
        a[j/2]=a[j];
        j=2*j;
    }
    a[j/2]=item;
}
void heapify(int a[],int n)
{
    for(i=n/2;i>0;i--) 
    adjust(a,i,n);  
}
void heapsort(a,n)
{    
   int x;
    heapify(a,n);
    while(n>0)
    {
     x=a[1];
    a[1]=a[n];
    a[n]=x;
    n--;
    adjust(a,1,n);
    }
}
void sort(a,n)
{    
   int x;
    for( int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        insert_tree(a,i);
    }

    while(n>0)
    {
     delete(a,&n,&x);
      a[n+1]=x;
    }
}

void insert_tree(int a[],int n)
{
    int i=n;
    int item=a[i];
    while(i>1&&a[i/2]<item)
    {
        a[i]=a[i/2];
        i=i/2;
    }
    a[i]=item;
}