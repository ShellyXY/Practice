//字符串连接
#include<stdio.h>
#define N 100

int main()
{
    char s[N],t[N],*p=s,*q=t;
    int i=0,j=0;
    printf("Input the first string:");
    while((s[i]=getchar())!='\n')
    {
        i++;
    }
    s[i]='\0';

    printf("Input the second string:");
    while((t[j]=getchar())!='\n')
    {
        j++;
    }
    t[j]='\0';
    j=0;
    while((s[i]=t[j])!='\0')
    {
        i++;
        j++;
    }
    puts(s);

    system("pause");
    return 0;
    
}