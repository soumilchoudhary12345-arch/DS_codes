#include<stdio.h>
#define N 10
typedef struct 
{
    int arr[N];
    int rear,front;
}queue;
void enqueue(queue*q,int x)//push
{
    if(q->rear==N-1)
        printf("queue overflowed");
    else
    {
        q->rear++;
        q->arr[q->rear]=x;
    }
}
int isempty(queue* q)
{
    if(q->front==q->rear+1)
        return 1;
    return 0;
}
int dequeue(queue* q)//pop
{
    int x;
    if(isempty(q))
        return -1;
    else
    {
        x=q->arr[q->front];
        q->front++;
        return x;
    }
}
int peek(queue* q)
{
    return(q->arr[q->front]);
}
void display(queue* q)
{
    int i=q->front;
    if(isempty(q))
        printf("queue is empty nothing to display");
    else
    {
        while (i<=q->rear)
        {
            printf("%d\t",q->arr[i]);
            i++;
        }
    }
    printf("\n");
}
int main()
{
    int ch,x;
    queue q;
    q.front=0;
    q.rear=-1;
    while(1)
    {
        printf("enter 1 for enqueue\nenter 2 for dequeue\nenter 3 for isempty\nenter 4 for display\nenter 5 to exit code\n");
        printf("enter the choice:");
        scanf("%d",&ch);
        if(ch==5)
            break;
        switch (ch)
        {
            case 1://enqueue
            {
                printf("enter the number to enter in the queue\n");
                scanf("%d",&x);
                enqueue(&q,x);
            }break;
            case 2://dequeue
            {
                if(x==-1)
                    printf("queue is empty\n");
                else
                {
                    x=dequeue(&q);
                    printf("the deleted element is  %d\n",x);
                }
            }break;
            case 3://isempty
            {
                if(isempty(&q))
                    printf("queue is empty\n");
                else
                    printf("queue is not empty\n");
            }break;
            case 4://display
            {
                display(&q);
            }break;
        }
    }
    printf("turminated!!!");
    return 0;
}