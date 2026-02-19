#include<stdio.h>
#define N 15
#include<string.h>
typedef struct stack 
{
    int a[N];
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
int pop(stack* s)
{
    char x;
    if(isempty(s))
    {
        printf("the stack has underflowed");
    }
    else
    {
    x=s->a[s->top];
    s->top--;
    return x;
    }
}
int isoperand(char x)
{
    if(x<=9&&x>=0)
        return 1;
    return 0;
}
int isoprator(char x)
{
    if(x=='+'||x=='-'||x=='*'||x=='/')
        return 1;
    return 0;
}
int eval(char postfix[])
{
    int i,n=strlen(postfix),v;
    char x;
    stack s;
    s.top=-1;
    char op1,op2;
    for(i=0;i<n;i++)
    {
        x=postfix[i];
        if(isoperand(x))
        {
            push(&s,(int)x-48);//-48 for zero ascii value
        }
        else if(isoperator(x))
        {
            op1=pop(&s);
            op2=pop(&s);
            if(x=='+')
            {
                v=op1+op2;
            }
            else if(x=='-')
            {
                v=op2-op1;//order matters the ele 1st poped is the second operasnd a-b=ab-
            }
            else if(x=='/')
            {
                v=op2/op1;//order matters the ele 1st poped is the second operasnd a/b=ab/
            }
            else if (x=='*')
            {
                v=op1*op2;
            }
        }
    }
    return (pop(&s));  
}
int main()
{
    int z;
    char  postfix[N];
    stack s;
    s.top=-1;
    printf("enetr the postfix epression");
    gets(postfix);
    z=eval(postfix);
    printf("the rresult is :%d",z);
}