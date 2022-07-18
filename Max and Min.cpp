#include<stdio.h>
void MaxMin(int a[],int l,int h,int* max,int* min)
{
    int mid,max1,min1;
    if(l==h)
        *max=*min=a[l];
    else if(l==h-1)
    {
        if(a[l]>a[h])
        {
        *max=a[l];
        *min=a[h];
        }
        else
        {
        *max=a[h];
        *min=a[l];
        }
    }
    else
    {
        mid=(l+h)/2;
        MaxMin(a,l,mid,max,min);
        MaxMin(a,mid+1,h,&max1,&min1);
        
        if(*max<max1)
        *max=max1;
        if(*min>min1)
        *min=min1;
        
    }
}
int main()
{
    int a[20],i,s,max,min;
    printf("enter size:");
    scanf("%d",&s);
    printf("\nENTER ELE IN ARRAY:\n");
    for(i=1;i<=s;i++)
    {
        scanf("%d",&a[i]);
    }
    MaxMin(a,1,s,&max,&min);
    printf("\n\tARRAY IS \n");
    for(i=1;i<=s;i++)
    {
        printf("%d ", a[i]);
    }
    printf("\nMAX: %d\n",max);
    printf("\nMIN: %d\n",min);
    return 0;
}