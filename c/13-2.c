#include<stdio.h>

int main(void)
{
    FILE *fp;
    int  CountOfPeople=0;               /*人数*/
    char Name[100];                     /*姓名*/
    double Height,Weight;               /*身高，体重*/
    double HeightAll = 0.0;             /*身高合计*/
    double WeightAll = 0.0;             /*体重合计*/

    if((fp=fopen("hw.dat","r"))==NULL)
    {
        printf("\aThe file open failure.\n");
    }
    else
    {
        while(fscanf(fp,"%s%lf%lf",Name,&Height,&Weight)==3)
        {
            printf("%-10s %5.1f  %5.1f\n",Name,Height,Weight);
            CountOfPeople++;
            HeightAll+=Height;
            WeightAll+=Weight;
        }
        printf("--------------------------\n");
        printf("The Average    %5.1f  %5.1f\n",HeightAll/CountOfPeople,WeightAll/CountOfPeople);
        fclose(fp);
    }

    system("pause");
    return 0;
}