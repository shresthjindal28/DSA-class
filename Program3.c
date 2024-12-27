#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define max_size 5
int stack[max_size],top=-1,flag=1;
int i,temp,item,rev[max_size],num[max_size];

void push();
void pop();
void display();
void pali();
void main()
{
    int choice;
    printf("\n\nSTACK OPERATION\n");
    printf("1.Push\n");
    printf("2.Pop\n");
    printf("3.Palindrome\n");
    printf("4.Display\n");
    printf("5.Exit\n");
    printf(" ");
    while(1)
    {
        printf("\nEnter your choice\t");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                if(flag)
                temp=top;
                break;
            case 3:
                pali();
                top=temp;
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
                break;
            default:
            printf("\n Invalid choice\n");
            break;
        }
    }
}
void push()
{
    if(top==(max_size-1))
    {
        printf("\n Stack overflow");
    }
    else
    {
        printf("Enter the element to be inserted\t");
        scanf("%d",&item);
        top++;
        stack[top]=item;
    }
    temp=top;
}
void pop()
{
    if(top==-1)
    {
        printf("\n Stack underflow");
        flag=0;
    }
    else{
        item=stack[top];
        top--;
    }
}
void pali()
{
    i=0;
    if(top==-1)
    {
        printf("\nPush some element to the stack first");
    }
    else
    {
        while(top!=-1)
        {
            rev[top]=stack[top];
            pop();
        }
        top=temp;
        for(i=0;i<=temp;i++)
        {
            if(stack[top--]==rev[i])
            {
                if(i==temp)
                {
                    printf("numbers in stack is palindrome\n");
                    return;
                }
            }
        }
        printf("Numbers in stack is not palindrome\n");
        }
}
void display()
{
    int i;
    top=temp;
    if(top==-1)
    {
        printf("Stack is empty\n");
    }
    else
        {
        printf("\nStacke elments are ");
        for(i=top;i>=0;i--)
        {
            printf("%d\n",stack[i]);
        }
        
    }
}