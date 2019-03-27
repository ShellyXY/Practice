//求数组长度
#include<stdio.h>
#define N 100
int main()
{
    char sa[N],*p=sa;
    printf("Please input the string:\n");
    scanf("%s",sa);
    while(*p!='\0')
    {
        p++;
    }
    printf("The length of the string is %d\n",p-sa);
    printf("%d %d",p,sa);
    system("pause");
    return 0;
}