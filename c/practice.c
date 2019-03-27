//回文数
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int num,s,y=0;
    printf("Please input the number:\n");
    scanf("%d",&num);
    s=num;
    while(s>0)
    {
        y=y*10+s%10;
        s=s/10;
    }
    if(y==num)
    {
        printf("The number is the palindrome number");
    }
    else
    {
        printf("Not the palindrome number");
    }
    
    system("pause");
    return 0;
}