/*
显示字符串数组（函数版）
*/
#include<stdio.h>
/*---显示字符串数组---*/
void put_strary(const char s[][6],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("s[%d]=\"%s\"\n",i,s[i]);
    }
}

int main(void)
{
    char cs[][6]={"Turbo","NA","DOHC"}; 
    put_strary(cs,3);

    system("pause");
    return 0; 
}