#include<stdio.h>
#include<string.h>
#define N 15
typedef struct stack 
{
    char a[20];
    int top;
}stack;
void push(stack* s,char x)
{
    if(s->top==N-1)
    {
        printf("the stack has overflowed");
    }
    else
    {
        s->top++;
        x=s->a[s->top];
    }
}
int isempty(stack* s)
{
    if(s->top==-1)
        return 1;
    return 0;
}
char pop(stack* s)
{
    char x;
    x=s->a[s->top];
    s->top--;
    return x;
}
int type_of_bracket(char x)
{
    if(x=='{'||x=='['||x=='(')
    {
        return 1;//open bracket
    }
    else if(x=='}'||x==']'||x==')')
    {
        return 0;//closed bracket
    }
    return -1;
}
int check(char arr[])
{
    int n,i;
    stack s;
    char ele;
    s.top=-1;
    n=strlen(arr);
    for(i=0;i<n;i++)
    {
        if(type_of_bracket(arr[i])==1)
        {
            push(&s,arr[i]);
        }
        else if(type_of_bracket(arr[i])==0)
        {
            if(isempty(&s))
                return 0;
            else
            {
                ele=pop(&s);
                if((ele=='{'&&arr[i]!='}')||(ele=='('&&arr[i]!=')')||(ele=='['&&arr[i]!=']'))
                {
                    return 0;
                }
            }
        }
    }
    if(isempty(&s))
        return 1;
    return 0;
}
int main()
{
    char arr[20];
    printf("enter the expression");
    gets(arr);
    if(check(arr))
        printf("valid");
    else
        printf("invalid");
}