#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
void insert_sort(int *a,int len)
{
    int temp;
    int i,j;
    for(i=1;i<len;i++)
    {
        temp=a[i];
        j=i-1;
        while(j>=0&&a[j]>temp)
        {
            a[j+1]=a[j];   //向右移动一位
            j--;
        }
        a[j+1]=temp;
    }
}
int main(void)
{
    int i;
    int len,num;
    int *a;

    printf("Please input the number of the value you want to sort:");
    scanf("%d",&len); //存储要排序的数的个数
    a=(int*)malloc(num*len*sizeof(int));

    printf("please input the value you want to search");
    for(i=0;i<len;i++)
    {
        scanf("%d",&a[i]);
    }
    
    printf("The value you input is:");
    for(i=0;i<len;i++)
    {
        printf("%d",a[i]);
    }

    insert_sort(a,len);

    printf("The value you sort is:");
    for(i=0;i<len;i++)
    {
        printf("%d",a[i]);
    }
    
    system("pause");
    return 0;
}