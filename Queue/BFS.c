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
    
}