#include<stdio.h>


void swap(int *a,int *b)
{
    int temp;

    temp=*a;
    *a=*b;
    *b=temp;
}
void BubbleSort_(int b[])
{
    int i,j;
    for(i=0;i<10;i++)
    {
        for(j=9;j>i;j--)   //从后面往前 
        {
            if(b[j-1]>b[j])
            {
                swap(&b[j-1],&b[j]);
            }
        }
    }
}

void display(int b[])
{
    int i;
    for(i=0;i<10;i++)
    {
        printf("%d ",b[i]);
    }

}

int main()
{
    int i=0;
    int a[10]={2,1,5,7,4,3,9,8,0,6};
    BubbleSort_(a);
    display(a);
    system("pause");
    return 0;
}
