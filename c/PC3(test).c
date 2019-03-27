#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

#define LEN 128

bool isValidIp(const char *ip)
{
    int dots=0;       //代表字符.的个数
    int setions=0;    //IP每一个部分的总和（0-225）

    if(ip==NULL||*ip=='.')
    {
        return false;
    }

    while(*ip)
    {
        if(*ip=='.')
        {
            dots++;
            if(setions>=0&&setions<=225)
            {
                setions=0;
                ip++;
                continue;
            }
            return false;
        }
        else if(*ip>='0'&&ip<='9')
        {
            setions=setions*10+(*ip-'0');
        }
        else
        {
            return false;
        }
        ip++;      
    }

    //判断IP最后一段是否合法
    if(setions>=0&&setions<=255)
    {
        if(dots==3)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int num;
    int i;

    printf("please input the num:");
    scanf("%d",&num);
    char **a=(char **)malloc(num*sizeof(char *));
    for(int i=0;i<num;i++)
    {
        a[i]=(char *)malloc(LEN*sizeof(char));
    }

    for(int i=0;i<num;i++)
    {
        scanf("%s",a[i]);
    }
    for(int i=0;i<num;i++)
    {
        if(isValidIp(a[i]))
        {
        printf("Is Valid Ip-->[%s]\n",a[i]);
        
        }
        else
        {
        printf("Is Invalid IP-->[%s]\n",a[i]);
        }
    }
    getchar();
    system("pasue");
    return 0;
}