#include<stdio.h>
#define N 15
typedef struct stack 
{
    int a[N];
    int top;
}stack;
void push(stack* s,int x)
{
    if(s->top==N-1)
    
    {
        printf("the stack has overflowed");
    }
    else
    {
        s->top++;
        s->a[s->top]=x;
    }
}
int isempty(stack* s)
{
    if(s->top==-1)
        return 1;
    return 0;
}
int pop(stack* s)
{
    char x;
    if(isempty(s))
    {
        printf("the stack has underflowed");
        return -1;
    }
    else
    {
        x=s->a[s->top];
        s->top--;
        return x;
    }
}
void convert(stack* input,stack* output)
{
    int x,top;
    top=input->top;
    while(input->top!=-1)
    {
        x=input->a[input->top];
        push(output,x);
        input->top--;
    }
    input->top=top;
}
void peek(stack* s)
{
    int x;
    x=s->top;
    printf("the top of stack is %d",x);
}
int main()
{
    int ch,x;
    stack input,output;
    input.top=-1;
    output.top=-1;
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
                push(&input,x);
            }break;
            case 2://dequeue stack like behaviour
            {
                output.top=-1;
                convert(&input,&output);
                x=pop(&output);
                printf("the deleted element is  %d\n",x);
            }break;
            case 3:
            {
                if(isempty(&input))
                    printf("the queue is empty");
                else
                    printf("the queue is not empty");
            }
            case 4://peek stack like behaviour
            {
                convert(&input,&output);
                peek(&output);
            }
        }
    }
    printf("turminated!!!");
    return 0;
}