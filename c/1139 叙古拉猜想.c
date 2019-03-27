//从一个正整数开始，两人轮流进行如下运算：
/*奇数，把这个数乘以3再加1；若是偶数，就把这个数除以2。直到第一次得到1才结束
*/
#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int a,count=0;
        scanf("%d",&a);
        if(a==1)
        {
            count=1;
        }
        else
        {
        while(a!=1)
        {
            a=(a%2==1)?(a*3+1):a/2;
            count++;}
        }
        if(count%2==0)
        {
            printf("I lost!\n");
        }
        else
        {
            printf("I win!\n");
        }
    }
    return 0;
}

