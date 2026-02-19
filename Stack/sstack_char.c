#include<stdio.h>
#define N 15
#define M 10
#include<string.h>
typedef struct stack 
{
    char a[N][M];
    int top;
}stack;
void push(stack* s,char x[])
{
    if(s->top==N-1)
    {
        printf("the stack has overflowed");
    }
    else
    {
        s->top++;
        strcpy(s->a[s->top],x);
    }
}
int isempty(stack* s)
{
    if(s->top==-1)
        return 1;
    return 0;
}
void pop(stack* s)
{
    char x[M];
    if(isempty(s))
    {
        printf("the stack has underflowed");
    }
    else
    {
    strcpy(x,s->a[s->top]);
    s->top--;
    printf("the deleted element is %s",x);
    }
}
int peek(stack* s)
{
    if(isempty(s))
        return 0;
    printf("the top elemint is %s",s->a[s->top]);
    return 1;
}
int main()
{
    int ch;
    char  x[M];
    stack s;
    s.top=-1;
    printf("\nMenu \n 1-PUSH\n2-POP\n3-PEEK\n4-isempty\n-1---exit\n");
    printf("enter the choice:");
    do
    {
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("enter the element");
                scanf("%s",x);
                push(&s,x);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                peek(&s);
                break;
            case 4:
                if(isempty(&s))
                {
                    printf("the stack is empty");
                    break;
                }
                else
                {
                    printf("the stack has elements");
                    break;
                }
        }
    }while(ch>0);
    printf("\nyou have exited the command");
}