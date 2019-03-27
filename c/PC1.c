#include<stdlib.h>
#include<stdio.h>

void QuickSort(int A[],int low,int high)
{
    if(low<high)              //递归跳出的条件
    {
        //Parttion()就是划分操作，将表A[low...high]划分为满足上述条件的两个子表
        int pivotpos = Partition(A,low,high);
        QuickSort(A,low,pivotpos-1);
        QuickSort(A,pivotpos+1,high);
    }   
}

int Partition(int A[],int low,int high)
{
    int pivot=A[low];            //当前表中第一个元素设为枢轴值，对表进行划分
    while(low<high)
    {
        while(low<high&&A[high]>=pivot)  --high;
        A[low]=A[high];
        while(low<high&&A[low]<=pivot)   ++low;
        A[high]=A[low];
    }
    A[low]=pivot;
    return low;
}

int main()
{
    int *a;
    int len;
    int group;
    int i;

    printf("Please input the number of the value you want to sort:");
    scanf("%d",&len); //存储要排序的数的个数

    printf("Please input the group:");
    scanf("%d",&group); //存储组数
    a=(int*)malloc(group*len*sizeof(int));

    for(i=0;i<group*len;i++)
    {
        scanf("%d",&a[i]);
    }

    for(i=0;i<group;i++)
    {
        QuickSort(a,len*i,(len-1)+len*i);
    }

    printf("The value you sorted is:\n");
    for(i=0;i<group*len;i++)
    {
        printf("%d ",a[i]);
        if((i+1)%len==0)
        {
            printf("\n");
        }
    }

    system("pause");
    return 0;


}