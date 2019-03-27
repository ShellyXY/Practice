#include<stdio.h>
#include<stdlib.h>

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

void display(int array[], int maxlen)
{
    int i;
 
    for(i = 0; i < maxlen; i++)
    {
        printf("%-3d", array[i]);
    }
    printf("\n");
 
    return ;
}

int main()
{
    int n;
    int array[10]={12,35,25,16,34,23,49,45,17,31};
    int maxlen=10;

    printf("The Sequence before sort:\n");
    display(array,maxlen);

    QuickSort(array,0,9);

    printf("The Sequence after sort:\n");
    display(array,maxlen);

    system("pause");
    return 0;

    
}