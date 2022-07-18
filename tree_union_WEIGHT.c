#include<stdio.h>
int p[11],s[11],n;
int find(int i)
{
    for(; p[i]>0;)
    {
        i=p[i];
    }
    return i;
}
int Union(int i,int j)
{
    int t=p[i]+p[j];
    if(p[i]<=p[j])
    {
        p[j]=i;
        p[i]=t;
        return j;
    }
    else
    {
        p[i]=j;
        p[j]=t;
        return i;
    }
}
void collisionFIND(i)
{
    int r=i,s;
    for(; p[i]>0;)
    {
        i=p[i];
    }
    while(p[r]!=i)
    {
        s=p[r];
        p[r]=i;
        r=s;
    
    }   
    return i;

}
int main()
{
    int i,c;
    //if root node of  aset the  p[i]=-1
    printf("\nenter no of sets:");
    scanf("%d",&n);
    int r=1;
    for(i=1; i<=10; i++)
    {
        printf("\nPARENTS OF %d is:",i);
        scanf("%d",&p[i]);
        if(p[i]>0)
        {
        s[r]=i;
        r=r+1;}      
    }
    for(i=1;i<=10;i++)
    {
     r=find(i);
     if(r!=i)
     p[r]--;
    }
    //for(r=1;r<=10;r++)
    //printf("node%d par%d   ",r,p[r]);
    printf("choose \n1.FIND SET\n2.UNION\n");
    scanf("%d",&c);
    switch(c)
    {
    case 1:
    {
        int e,x,k;
        printf("\n enter ele to find set");
        scanf("%d",&e);
        
        x=find(e);
        if(x==0)
            printf("\nele doesn't belong to any set\n");
        else {
            for(k=1; k<=n; k++)
            {  
                if(s[k]==x)
                    break;
            }
            printf("\nELE BELONG TO SET: S%d with root %d",k,x);
        }
        break;
    }
    case 2:
    {
       
        printf("\nENTER THE roots FOR UNION:");
        int i,j,k;
        scanf("%d %d",&i,&j);
         j= Union(i,j);
        for(k=1; k<=n; k++)
        {
            if(s[k]==j)
                break;
        }
        for(i=k; i<=n; i++)
        {
            s[i]=s[i+1];          
        }
        n--;       
    }
    }
    return 0;
}