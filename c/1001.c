#include<stdio.h>
int main()//二分查找
{
/*-------------变量定义区域--------------*/
    int n;//有序数组的长度，待查找数组的长度
    int m;//定义想要查找的元素
    int a[10000];//存放有序元素的数组
    int top=0,bot=0,mid=0;//定义二分查找的头和尾
/*--------------------------------------*/


/*-------------功能区域--------------*/
    printf("Please input the length of the array:\n");
    scanf("%d",&n);
    printf("Please input the value of the array ascending:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    printf("Please input the value you want to search:\n");
    scanf("%d",&m);
    top=n-1;
    mid=(top+bot)/2; 
    while(a[mid]!=m&&top>bot)
    {
       
        if(a[mid]<m)
        {
            bot=mid+1;
        }
        else if(a[mid]>m)
        {
            top=mid-1;
        }
        mid=(top+bot)/2; 
    }
    if(a[mid]==m)
    {
        printf("success");
    }
    else
    {
        printf("failure");
    }
    getchar();
}