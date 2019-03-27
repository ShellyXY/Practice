#include<stdio.h>
int PerfectNumber(int y)
{
    int j,sum;
    sum=0;
    for(j=1;j<=y/2;j++)
    {
        if(y%j==0)
        {
            sum=sum+j;
        }
    }
    if(sum==y)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int y,i;
    printf("Please input the number you want to check:\n");
    scanf("%d",&y);
    for(i=6;i<=y;i++)
    {
        if(PerfectNumber(i))
        {
            printf("%d\n",i);
        }
    }
    system("pause");
    return 0;
}
