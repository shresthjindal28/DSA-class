#include<stdio.h>
void main()
  {
    char STR[100],PAT[100],REP[100],ans[100];
    int i,j,c,m,k,flag=0;
    printf("\nEnter main string:\n");
    gets(STR);
    printf("\nEnter the pattern string:\n");
    gets(PAT);
    printf("\nEnter the repalce string:\n");
    gets(REP);
    i=m=c=j=0;
    while(STR[c]!='\0')
    {
        if (STR[m]==PAT[i])
        {
            i++;m++;
            flag=1;
            if(PAT[i]=='\0')
            {
                for(k=0;REP[k]!='\0';k++,j++)
                ans[j]=REP[k];
                i=0;
                c=m;
            }
        }
        else
        {
        ans[j]=STR[c];
        j++;
        c++;
        m=c;i=0;
        }
    }
    if (flag==0)
    {
    printf("\npattern isnot found");
    }
    else
    {
    ans[j]='\0';
    printf("\n the resultant string is:%s\n",ans);
    }}