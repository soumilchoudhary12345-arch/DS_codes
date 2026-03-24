#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
}node;
typedef struct LL
{
    node* start;
}LL;
int isempty(LL* l)
{
    if(l->start==NULL)
        return 1;
    return 0;
}
void insertbegin(LL* l,int x)
{
    node* new;
    new=(node*)malloc(sizeof(node));
    new->data=x;
    new->next=NULL;
    if(isempty(l))
    {
        l->start=new;
        return;
    }
    new->next=l->start;
    l->start=new;
}
void insertend(LL* l,int x)
{
    node *p,*new;
    p=l->start;
    new=(node*)malloc(sizeof(node));
    new->data=x;
    new->next=NULL;
    if(isempty(l))
    {
        l->start=new;
        return;
    }
    else if(l->start->next==NULL)
    {
        l->start->next=new;
        return;
    }
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=new; 
}
void insertat(LL*l,int x,int n)
{
    int i;
    node *p=l->start,*new,*q;
    new=(node*)malloc(sizeof(node));
    new->data=x;
    new->next=NULL; 
    for(i=1;i<n;i++)//before nth ele
    {
        p=p->next;
    }
    q=p->next;
    p->next=new;
    new->next=q;
}
void delbegin(LL* l)
{
    node* p;
    if(isempty(l))
        printf("\nlinked list is empty");
    else
    {
        p=l->start;
        l->start=l->start->next;
        printf("\nthe del ele is%d",p->data);
        free(p);
    }
}
void delend(LL* l)
{
    node* p,*q;
    p=l->start;
    if(isempty(l))
        printf("linked list is empty");
    else if(l->start->next==NULL)
    {
        q=l->start;
        l->start=NULL;
    }
    else
    {
        while(p->next->next!=NULL)
        {
            p=p->next;
        }
        q=p->next;
        p->next=NULL;
        printf("the del ele is %d",q->data);
    }
    free(q);
}
void delat(LL*l,int n)
{
    node *p,*i;
    int cnt=0;
    if(l->start==NULL)
    {
        printf("can't do ll empty");
        return;
    }
    else if(l->start->next==NULL)
    {
        p=l->start;
        l->start=NULL;
    }
    for(i=l->start;cnt<n-1;cnt++)
    {
        i=i->next;
    }
    p=i->next;
    i->next=i->next->next;
    free(p);
}
int main()
{
    LL l;
    l.start = NULL;

    int choice,x,n;

    while(1)
    {
        printf("\n------ LINKED LIST MENU ------");
        printf("\n1. Insert at Begin");
        printf("\n2. Insert at End");
        printf("\n3. Insert at Position");
        printf("\n4. Delete from Begin");
        printf("\n5. Delete from End");
        printf("\n6. Delete from Position");
        printf("\n7. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        if(choice==7)
            break;
 
        switch(choice)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d",&x);
                insertbegin(&l,x);
                break;

            case 2:
                printf("Enter element: ");
                scanf("%d",&x);
                insertend(&l,x);
                break;

            case 3:
                printf("Enter element: ");
                scanf("%d",&x);
                printf("Enter position: ");
                scanf("%d",&n);
                insertat(&l,x,n);
                break;

            case 4:
                delbegin(&l);
                break;

            case 5:
                delend(&l);
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d",&n);
                delat(&l,n);
                break;

            default:
                printf("Invalid choice");
        }
    }

    return 0;
}
