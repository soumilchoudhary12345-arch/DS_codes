#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next,*prev;
}node;
typedef struct DLL
{
    node* start;
}DLL;
int isempty(DLL* l)
{
    if(l->start==NULL)
        return 1;
    return 0;
}
void insertend(DLL* l,int x)
{
    node *p,*new;
    p=l->start;
    new=(node*)malloc(sizeof(node));
    new->data=x;
    new->next=NULL;
    new->prev=NULL;
    if(isempty(l))
    {
        l->start=new;
        return;
    }
    else if(l->start->next==NULL)
    {
        l->start->next=new;
        new->prev=l->start;
        return;
    }
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=new;
    new->prev=p; 
}
void delend(DLL* l)
{
    node *p,*q;
    p=l->start;
    if(isempty(l))
        printf("linked list is empty");
    else if(l->start->next==NULL)
    {
        q=l->start;
        l->start=NULL;
        free(p);
    }
    else
    {
        while(p->next->next!=NULL)
        {
            p=p->next;
        }
        q=p->next;
        p->next=NULL;
        q->prev=NULL;
        printf("the del ele is %d",q->data);
        free(q);
    }
}
void display(DLL* l,int x)
{
    node *q;
    if(l->start==NULL)
    {
        printf("list is empty");
        return;
    }
    else if(x!=1&&x!=2)
    {
        printf("invalid input");
        return;
    }
    q=l->start;
    if(x==1)
    {
        while(q!=NULL)
        {
            printf("%d\t",q->data);
            q=q->next;
        }
        printf("\n");
        return;
    }
    else 
    {
        while(q->next!=NULL)
        {
            q=q->next;
        }
        while(q!=NULL)
        {
            printf("%d\t",q->data);
            q=q->prev;
        }
        printf("\n");
        return;
    }
}
int main()
{
    DLL l;
    l.start=NULL;

    int ch,x;

    while(1)
    {
        printf("\n1 ----> Insert End");
        printf("\n2 ----> Delete End");
        printf("\n3 ----> Display");
        printf("\n4 ----> Exit");
        printf("\nEnter choice: ");
        scanf("%d",&ch);
        if(ch==4)
            break;
        switch(ch)
        {
            case 1:
            {
                printf("Enter element: ");
                scanf("%d",&x);
                insertend(&l,x);
            }break;

            case 2:
            {
                delend(&l);
            }break;

            case 3:
            {
                printf("\nenter 1--->forward order\n\t2--->reverse order");
                scanf("%d",&x);
                display(&l,x);
            }break;

            default:
                printf("Invalid choice\n");
        }
    }
}