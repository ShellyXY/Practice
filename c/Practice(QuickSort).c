#include<stdio.h>
#include<stdlib.h>
#define LEN 10

void QuickSort(int a[],int low,int high)
{
    if(low<high)               //递归跳出的条件
    {
        int pivotpos=Partition(a,low,high);      //中枢值，用来将数组划分为两个子表
        QuickSort(a,low,pivotpos-1);
        QuickSort(a,pivotpos+1,high);
    }
}

int Partition(int A[],int low,int high)
{
    int pivot=A[low];              //数组或者子表的最左边的值作为标记
    while(low<high)
    {
        while(low<high&&A[high]>=pivot) --high;
        A[low]=A[high];
        while(low<high&&A[low]<=pivot) ++low;
        A[high]=A[low];
    }
    A[low]=pivot;
    return low;
}

void display(int array[],int maxlen)
{
    int i;

    for(i=0;i<maxlen;i++)
    {
        printf("%-3d",array[i]);
    }
    printf("\n");
}

int main()
{
    int a[LEN]={3,1,2,5,0,9,8,6,7,4};
    int maxlen=10;

    printf("The Sequence before sort:\n");
    display(a,maxlen);

    QuickSort(a,0,9);
    
    printf("The Sequence after sort:\n");
    display(a,maxlen);

    system("pause");
    return 0;
}