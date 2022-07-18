#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct treenode
{
    int weight;
    struct treenode *lchild;
    struct treenode  *rchild;
};
struct node
{
    int size,fno;
    char fname;
    struct node *next;
};
struct node* create_list(int n,struct node* &head)
{
    struct node *traverse=NULL,*nn;
    for(int i=1; i<=n; i++)
    {
        nn=(struct node *)malloc(sizeof(struct node));
        printf("ENTER THE SIZE OF FILE %d:\n",i);
        scanf("%d",&nn->size);
        nn->next=NULL;
        nn->fno=i;
        nn->fname='X';
        if(head==NULL)
            head=nn;
        else
            traverse->next=nn;
        traverse=nn;
    }
    return head;
}
struct node* insert_list(struct node* &head,struct node *ptr)
{
    struct node* traverse=head;;
    if(head==NULL)
        head=ptr;
    else
    {
        while(traverse->next!=NULL)
        {
            traverse=traverse->next;
        }
        traverse->next=ptr;
    }
    return head;
}
struct node* least(struct node* &head)
{
    struct node* traverse,*min=head;
    if(head ==NULL)
    {
        printf("\nLIST IS EMPTY\n");
    }
    else if(head->next==NULL)
    {
        head=NULL;
    }
    else
    {
        traverse=head->next;
        while(traverse!=NULL)//finding minimum
        {
            if(min->size>traverse->size)
                min=traverse;
            traverse=traverse->next;
        }
        if(min==head)
        {
            head=head->next;
        }
        else
        {
            traverse=head;
            while(traverse->next!=min)//removing minimum
            {
                traverse=traverse->next;
            }
            traverse->next=min->next;
        }
    }
    printf("FILE: %c-%d ",min->fname,min->fno)    ;
    return min;
}
void display_list(struct node* head)
{

    printf("\nsize of files in list are\n");
    for(; head!=NULL; head=head->next)
        printf(" %d ",head->size);
    printf("\n");
}
struct treenode* create_node(int weight)
{
    struct treenode* ptr;
    ptr=(struct treenode *)malloc(sizeof(struct treenode));
    ptr->lchild=NULL;
    ptr->rchild=NULL;
    ptr->weight=weight;
    return ptr;
}
struct treenode* tree(int n,int &total,struct node* &head,struct treenode* &ptr)
{
    struct node* f1,f2;
    for(int i=1; i<=n-1; i++)
    {

        ptr=(struct treenode *)malloc(sizeof(struct treenode));
        //display_list(head);
        ptr->rchild=create_node((least(head))->size);
        ptr->lchild=create_node((least(head))->size);
        ptr->weight=(ptr->lchild->weight)+(ptr->rchild->weight);
        printf("recordes: %d\n",ptr->weight);
        total=total+ptr->weight;
        f1=(struct node *)malloc(sizeof(struct node));
        f1->size=ptr->weight;
        f1->next=NULL;
        f1->fno=i;
        f1->fname='Z';
        head=insert_list(head,f1);
    }
    return ptr;
}
int main()
{
    int n,total=0;
    struct node *nl,*head=NULL,*traverse;
    struct treenode *ptr=NULL;
    printf("ENTER THE NO OF FILES: ");
    scanf("%d",&n);
    create_list(n,head);
    display_list(head);
    ptr=tree(n,total,head,ptr);
    printf("\nTOTAL NO OF RECORD MOVED  = %d ",total);
}