#include<stdio.h>
#include<stdlib.h>

void QuickSort(int a[],int low,int high)   //快速排序
{
    if(low<high)              //作为判断条件，在做题目的时候，当后和前到一起的时候一趟快速排序就完成了
    {
        int partion=Partition(a,low,high);
        QuickSort(a,low,partion-1);
        QuickSort(a,partion+1,high);
    }
}

int Partition(int a[],int low,int high)    //确定
{
    int pivot=a[low];       //当前表中最左边的值作为中枢值
    while(low<high)
    {
        while(low<high&&pivot<a[high]) high--;
        a[low]=a[high];         //当不满足上述的条件是，就要将后面的值赋给前面，从而开始从前往后看
        while(low<high&&pivot>a[low])  low++;
        a[high]=a[low];
    }
    a[low] =  pivot;
    return low;  
}


void display(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%-3d",a[i]);
    }
    printf("\n");
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