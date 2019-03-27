#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 100

int main()
{
    int k,m,i;
    char sa[N]={'\0'},*p,*q;
    scanf("%s",sa);
    printf("\nPlease enter K,M=");
    scanf("%d %d",&k,&m);
    p=&sa[k-1];
    q=&sa[k+m-1];
    if(*p=='\0'&&*q=='\0')
    {
        printf("\nError\n");
    }
    else
    {
        while(*p++==*q++)
        {
            puts(sa);
        }  
    }    

    system("pause");
    return 0;
}