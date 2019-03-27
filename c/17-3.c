#include<stdio.h>
#include<stdlib.h>

int main()
{
    int A[3][3]={0};
    int B[3][3]={0};
    int result[3][3]={0};      /*定义三个矩阵*/

    /*读取矩阵A*/
    FILE *fp1 = fopen("C:\\Users\\m1801\\Desktop\\a.txt","rt");
    if(fp1==NULL)
    {
        printf("can not open file!\n");
        return -1;
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            fscanf(fp1,"%d",&A[i][j]);
        }
        fscanf(fp1,"\n");
    }




    //读取矩阵B
    FILE *fp2=fopen("C:\\Users\\m1801\\Desktop\\b.txt","rt");
    if(fp2==NULL)
    {
        return -1;
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            fscanf(fp2,"%d",&);
        }
    }
}