#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct day
{
    int date;
    char* dayname;
    char* activity;
};

void create(struct day* day)
{
    day->dayname=(char*)malloc(30*sizeof(char));
    day->activity=(char*)malloc(30*sizeof(char));
    printf("enter the day name \n");
    scanf("%s",day->dayname);
    printf("enter the date \n");
    scanf("%d",&day->date);
    printf("enter the activity \n");
    scanf("%s",day->activity);
}
void read(struct day* day,int size)

{
    int i;
    for(i=0;i<size;i++)
    {
        printf("enter the details of the day %d\n",i+1);
        create(&day[i]);
    }

}
void display(struct day*day,int size)
{
    int i;
    printf("day name \t date \t activity\t");
    for(i=0;i<size;i++)
    {   
        printf(" \n %s \t\t %d \t\t %s",day[i].dayname,day[i].date,day[i].activity);
    }
}
void freememory(struct day*day,int size)
{
    int i;
    for (i=0;i<size;i++)
    {
        free(day[i].dayname);
        free(day[i].activity);
    }
    
}
int main()
{
    int size;
    printf("enter the number of days \n");
    scanf("%d",&size);
    struct day* day=(struct day*)malloc(size*sizeof(struct day));
    if(day==0)
    {
        printf("memory not allocated");
        return 1;
    }
    read(day,size);
    display(day,size);
    free(day);    
    return 1;
}