#include<stdio.h>
void insert_sort(int s[],int n)
{
    int i,j;
    for(i=2;i<=n;i++)
    {
        s[0]=s[i];        //给监视哨赋值
        j=i-1;            //确定要比较元素的最右位
        while(s[0]<s[j])
        {
            s[j+1]=s[j];  //数据右移
            j--;          //移向左边一个未被比较的数
        }
        s[j+1]=s[0];      //在确定的位置插入s[i]
    }
}

int main()
{
    int a[11],i,l;
    printf("Please input the 10 values:\n");
    for(i=1;i<=10;i++)
    {
        scanf("%d",&a[i]);
    }

    printf("The value you input is:\n");
    for(i=1;i<=10;i++)
    {
        printf("%d ",a[i]);
    }

    l=sizeof(a)/sizeof(int);
    insert_sort(a,l);

    printf("The value sorted is:\n");
    for(i=1;i<=10;i++)
    {
        printf("%d ",a[i]);
    }

    system("pause");
    return 0;
}