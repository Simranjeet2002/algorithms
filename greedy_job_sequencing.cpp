#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct job_seq
{
    int jno;
    int deadline;
    int profit;
};
int jseq(struct job_seq* job,int n,int j[],int &tp)
{   
    int k,i,r,l;
    job[0].deadline=j[0]=0;
    j[1]=job[1].jno;   
    k=1;
    tp=tp+job[1].profit;  
    for(i=2; i<=n; i++)
    {
        r=k;
        while(job[j[r]].deadline>job[i].deadline&&job[j[r]].deadline!=r)
        {
            r--;
        }
        if(job[j[r]].deadline<=job[i].deadline&&job[i].deadline>r)
        {
            for(l=k; l>=r+1; l--)
                j[l+1]=j[l];
            k++;
            j[r+1]=job[i].jno;
            tp=tp+job[i].profit;
        }
    }
    return k;
}
int main()
{
    int n,i,k,tp=0,j[20];
    struct job_seq job[20],temp;
    printf("ENTER THE NO OF JOBS: ");
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        printf("\tFOR JOB %d:-\n",i) ;
        job[i].jno=i;
        printf("ENTER PROFIT: ");
        scanf("%d",&job[i].profit);
        printf("ENTER DEADLINE: ");
        scanf("%d",&job[i].deadline);
    }
    for(i=1; i<n; i++)
    {
        for(k=1; k<=n-i; k++)
        {
            if(job[k].profit<job[k+1].profit)
            {
                temp=job[k];
                job[k]=job[k+1];
                job[k+1]=temp;
            }
        }
    }
    printf("\nAFTER SORTING BASED ON PROFIT\n");
     for(i=1; i<=n; i++)
    {
        printf("\n\tJOB no%d:",job[i].jno);
        printf(" \nPROFIT: %d",job[i].profit);
        printf("\nDEADLINE: %d",job[i].deadline);
    }   
    k=jseq(job,n,j,tp);
    printf("\nORDER IS :\n");
    for(i=1; i<=k; i++)
    {
        printf("J%d  ",j[i]);
    }
    printf("\nTOTAL PROFIT: %d",tp);
    return 0;
}