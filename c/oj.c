#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
#include<stddef.h>

int str_length(const char s[])
{
    int len=0;
    while(s[len])
    {
        len++;
    }
    return len;
}

/*练习9-5*/
int str_char(const char s[],int c)
{
    int len=0;
    while((int)s[len]!=c)
    {
        len++;
    }
    return len;
}

/*练习9-6*/
int str_chnum(const char s[],int c)
{
    int len=0;
    int count = 0;
    while(s[len])
    {
        if((int)s[len]==c)
        {
            count++;
        }
        len++;
    }
    return count;
}



int main(void)
{
    char str[128];
    int ch;
    printf("Please input the character you want to search:");
    ch=getchar();

    printf("Please input the string:");
    scanf("%s",str);

   
    //printf("The \"%c\" is in %d",ch,str_char(str,ch));

    //printf("The \"%c\" appear %d times in the str",ch,str_chnum(str,ch));
    

    system("pause");
    return 0;

}