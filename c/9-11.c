#include<ctype.h>
#include<stdio.h>

/*---字符串中的英文字符转为大写字符---*/
void str_toupper(char s[])
{
    int i=0;
    while(s[i])
    {
        s[i]=toupper(s[i]);
        i++;
    }
}

/*---字符串中的英文字符转为小写字符---*/
void str_tolower(char s[])
{
    int i=0;
    while(s[i])
    {
        s[i]=tolower(s[i]);
        i++;
    }
}

/*---练习9-10---*/
/*---将字符串中的s中的数字字符全部删除---*/
void del_digit(char s[])
{
    int len=0;
    int cot=0;
    char str1[128]={0};
    while(s[len])
    {
        if(s[len]<'0'||s[len]>'9')
        {
            str1[cot]=s[len];
            cot++;
        }
        len++;
    }

    printf("The string contain:%s\n",str1);
}

int main(void)
{
    char str[128];

    printf("Please input a string:");
    scanf("%s",str);

    str_toupper(str);
    printf("The Upper character is:%s\n",str);

    str_tolower(str);
    printf("The Lower character is:%s\n",str);

    del_digit(str);
    

    system("pause");
    return 0;


}
