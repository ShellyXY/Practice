#include<stdio.h>
int main()
{
    int i,j,k;
    int m,n;
    int flag;
    int top,bot,mid;
    int a[100000],b[100000];
    printf("Please input the array length:\n");
    scanf("%d",&n);
    printf("please input the array value ascending:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Please input the length of the array you want to serach:\n");
    scanf("%d",&m);
    printf("Please input the array you want to search");
    for(j=0;j<m;j++)
    {
        scanf("%d",&b[j]);//代表的是要查找的数
    }
    for(k=0;k<m;k++)
    {
        flag=0;
        bot=0;
        top=n-1;
        mid=(bot+top)/2;
        while(b[k]!=a[mid]&&top>=bot)
        {
            if(b[k]>a[mid])
            {
                bot = mid + 1;
            }
            else
            {
                top=mid-1;
            }
        }
        if(b[k]==a[mid])
            flag=1;        
        if(flag)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }

    } 
    return 0;
    getchar();  
}