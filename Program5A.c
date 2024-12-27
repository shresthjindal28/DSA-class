// Online C compiler to run C program online
#include<stdio.h>
#include<math.h>
#define MAX 10
int stack[MAX];
int top=-1;
void push(int val)
{
    if(top>=MAX)
    {
        printf("\nStack overflow");
    }
    else
    {
        top++;
        stack[top]=val;
    }
}
int pop()
{
    int x;
    if(top<=-1)
    {
        printf("Stack underflow");
    }
    else
    {
        x=stack[top];
        top--;
        return x;
    }
}
int main()
{
    char exp[20];
    printf("\nEnter the postfix expression:");
    scanf("%s",exp);
    int i,val1,val2;
    for(i=0;exp[i]!='\0';i++)
    {
        printf("%c",exp[i]);
        if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'||exp[i]=='%'||exp[i]=='^')
        {
            val1=pop();
            val2=pop();
            if(exp[i]=='+')
            {
                push(val2+val1);
            }
            if(exp[i]=='-')
            {
                push(val2-val1);
            }
            if(exp[i]=='*')
            {
                push(val2*val1);
            }
            if(exp[i]=='/')
            {
                push(val2/val1);
            }
            if(exp[i]=='%')
            {
                push(val2%val1);
            }
            if(exp[i]=='^')
            {
                push(pow(val2,val1));
            }
        }
        else
        {
            push(exp[i]-'0');
        }
    }
    printf("\nAnswer=%d",stack[top]);
    return 0;
}