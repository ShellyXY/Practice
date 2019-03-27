#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

bool isValidIp(const char *ip)
{
    int dots=0;     //字符.的个数
    int setions=0;  //IP每一部分的总和（0-225）

    if(NULL==ip||*ip=='.')  //排除输入参数为NULL,或者一个字符为‘.’的字符串
    {
        return false;
    }

    while(*ip)
    {
        if(*ip=='.')
        {
            dots++;
            if(setions>=0&&setions<=255)   //检查ip是否合法
            {
                setions=0;
                ip++;
                continue;
            }
            return false;
        }
        else if(*ip>='0'&&ip<='9')      //判断是不是数字
        {
            setions=setions*10+(*ip-'0');  //求每一段总和
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

void help()
{
    printf("Usage: ./test <ip str>\n");
    exit(0);   
}
int main(int argc,char **argv)
{
    if(argc!=2)
    {
        help();
    }

    if(isValidIp(argv[1]))
    {
        printf("Is Valid Ip-->[%s]\n",argv[1]);
    }
    else
    {
        printf("Is Invalid IP-->[%s]\n",argv[1]);
    }
    
    system("pause");
    return 0;
}