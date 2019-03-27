//字符串拷贝程序
#include<stdio.h>
#define N 100
int main()
{
     int i=0;
     char sa[N],sb[N];
     printf("Input the string:");
     scanf("%s",sa);
     while((sb[i]=sa[i])!='\0')
     {
         i++;
     }
     puts(sb);
}