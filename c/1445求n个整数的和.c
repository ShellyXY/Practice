#include<stdio.h>
int main()
{
    int n=0;         /*用来存储需要输入多少个整数*/
    int i=0;         /*用来计数所输入整数的个数*/
    int temp=0;      /*用来表示当前整数的变量*/
    int sum=0;       /*用来表示所求的和*/
    printf("Please input the number of the value you want:\n");
    scanf("%d",&n);
    printf("The value of each number:\n");
    while(i<n)
    {
        scanf("%d",&temp);
        sum+=temp;
        i++;
    }
    printf("the value of the sum is %d\n",sum);
    getchar(); 
    getchar();
    return 0;
   
}