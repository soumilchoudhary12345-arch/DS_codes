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
void display(LL* l)
{
    node *q;
    if(l->start==NULL)
    {
        printf("list is empty");
        return;
    }
    q=l->start;
    while(q!=NULL)
    {
        printf("%d\t",q->data);
        q=q->next;
    }
    printf("\n");
    return;
}
void copy(LL*l,LL* lc)
{
    node *p;
    lc->start=NULL;
    p=l->start;
    while(p!=NULL)
    {
        insertend(lc,p->data);
        p=p->next;
    }
}
void sort(LL*l,int x)
{
    node *i,*j;
    int temp;
    if(x==1)//decending
    {
        for(i=l->start;i->next!=NULL;i=i->next)
        {
            for(j=i;j->next!=NULL;j=j->next)
            {
                if((j->data)<(j->next->data))
                {
                    temp=j->data;
                    j->data=j->next->data;
                    j->next->data=temp;
                }
            }
        }
    }
    else//asscending
    {
        for(i=l->start;i->next!=NULL;i=i->next)
        {
            for(j=l->start;j->next!=NULL;j=j->next)
            {
                if((j->data)>(j->next->data))
                {
                    temp=j->data;
                    j->data=j->next->data;
                    j->next->data=temp;
                }
            }
        }
    }
}
int main()
{
    LL l, lc;
    int choice, x, order;

    l.start = NULL;
    lc.start = NULL;

    while(1)
    {
        printf("\n===== LINKED LIST MENU =====\n");
        printf("1. Insert at End\n");
        printf("2. Display List\n");
        printf("3. Copy List\n");
        printf("4. Sort List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                insertend(&l, x);
                break;

            case 2:
                printf("Original List:\n");
                display(&l);
                break;

            case 3:
                copy(&l, &lc);
                printf("Copied List:\n");
                display(&lc);
                break;

            case 4:
                printf("Enter 1 for Descending, 0 for Ascending: ");
                scanf("%d", &order);
                sort(&l, order);
                printf("Sorted List:\n");
                display(&l);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}