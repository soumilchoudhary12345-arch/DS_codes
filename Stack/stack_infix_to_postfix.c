#include<stdio.h>
#include<string.h>
#define N 20
typedef struct stack
{
    char arr[N];
    int top;
}stack;
void push(stack* s,char x)
{
    s->top++;
    s->arr[s->top]=x;
}
char pop(stack* s)
{
    char x;
    x=s->arr[s->top];
    s->top--;
    return x;
}
int isoperand(char x)
{
    if('a'<=x&&x<='z'||'A'<=x&&x<='Z')
        return 1;
    return 0;
}
int isoperator(char x)
{
    if(x=='*'||x=='/'||x=='+'||x=='-'||x=='%')
        return 1;
    return 0;
}
int priority(char x)
{
    if(x=='/'||x=='*'||x=='%')
        return 3;
    else if (x=='+'||x=='-')
        return 2;
    return 1;
}
char stacktop(stack* s)
{
    char x=s->arr[s->top];
    return x;
}
int isempty(stack* s)
{
    if(s->top==-1)
        return 1;
    return 0;
}
void convert(char infix[],char postfix[])
{
    int n,i,cnt=0;
    char x;
    stack s;
    s.top=-1;
    n=strlen(infix);
    for(i=0;i<n;i++)
    {
        x=infix[i];
        if(isoperand(x))
            postfix[cnt++]=x;
        else if(x=='(')
            push(&s,x);
        else if(isoperator(x))
        {
            if(isempty(&s))
                push(&s,x);
            else
            {
                while(priority(stacktop(&s)>=priority(x)))
                {
                    postfix[cnt++]=pop(&s);
                }
                push(&s,x);
            }
        }
        else//close bracket
        {
            if(isempty(&s))
                push(&s,x);
            else
            {
                while(stacktop(&s)!='(')
                {
                    postfix[cnt++]=pop(&s);
          
                }
                pop(&s);
            }
        }
    }
    while(isempty(&s)==0)
    {
        postfix[cnt++]=pop(&s);
    }
    postfix[cnt]='\0';
}
int main()
{
    char infix[N],postfix[N];
    gets(infix);
    convert(infix,postfix);
    printf("%s",postfix);
    return 0;
}