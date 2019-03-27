#include<stdio.h>

/*显示字符串s*/

void put_string(const char s[])
{
    int i=0;
    while(s[i])
    {
        putchar(s[i++]);
    }
}

/*练习9-7*/
void put_stringn(const char s[],int n)
{
    
    for(int a=1;a<n;a++)
    {
        int i=0;
        while(s[i])
        {
            putchar(s[i++]);
        }
    }
}

/*练习9-8*/
void put_stringr(const char s[])
{
    int len=0;
    while(s[len])
    {
        len++;
    }
    while(s[len-1])
    {
        putchar(s[--len]);
    }


}

int main(void)
{
    char str[128];
    int times;
    printf("please input the string:");
    scanf("%s",str);
    //printf("The times you want to print");
    //scanf("%d",&times);

    //printf("The string you input is:");
    //put_string(str);
    //put_stringn(str,times);
    //printf("\n");

    printf("The reverse string you input is:");
    put_stringr(str);


    system("pause");
    return 0;
}