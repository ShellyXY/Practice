/*
   显示字符串数组（函数版：逐字符遍历）
*/
#include<stdio.h>

/*---显示字符串数组（逐个显示字符）---*/
void put_strary2(const char s[][6],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        int j=0;
        printf("s[%d]=\"",i);

        while(s[i][j])
        {
            putchar(s[i][j++]);
        }
        puts("\"");
    }
}

int main(void)
{
    char cs[][6]={"Turbo","NA","DOHC"};
    put_strary2(cs,3);

    system("pause");
    return 0;
}