#include<stdio.h>
#include<string.h>

int main()
{
    char str[100]={"I Love You"};
    char temp[100];
    strcpy(temp,strstr(str,"Love"));
    printf("%s",temp);

    system("pause");
    return 0;
}