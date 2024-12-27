#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define max_size 5
int queue[max_size],rear=-1,flag=1,front=-1;
int i,temp,item;

void insert();
void delete();
void display();
void main()
{
    int choice;
    printf("\nCIRCULAR QUEUE OPERATION\n");
    printf("1.insert\n");
    printf("2.delete\n");
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
                insert();
                break;
            case 2:
                delete();
                if(flag)
                temp=front;
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
            printf("\n Invalid choice\n");
            break;
        }
    }
}
  void insert()
{
    if(front==(rear+1) % max_size)
    {
        printf("queue is full");
    }
    else
    {
        int item;
        printf("enter the item");
        scanf("%d",&item);
        if (front==-1)
            front=0;
            rear=(rear+1) % max_size;
            queue[rear]=item;
        
    }
}
void delete()
{
    if (front==-1 && rear==-1)
    {
        printf("stack underflow");
    }
    else
    {
        if(front==rear)
        {
            printf("dequed element %d",queue[front]);
            front=rear-1;
        }
        else{
            printf("dequed element %d\n",queue[front]);
            front=(front+1)%max_size;
        }
    }
}
void display()
{
    int i;
    for (i=front;i<=rear;i++)
    printf("%d\n",queue[i]);
}