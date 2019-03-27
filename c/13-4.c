#include<time.h>
#include<stdio.h>

char data_file[]="datetime.dat";

/*取得并显示上一次运行的时间*/
void get_data(void)
{
    FILE *fp;
    if((fp=fopen(data_file,"r"))==NULL)
    {
        printf("The program is excute the first time.\n");
    }
    else
    {
        int year,month,day,h,m,s;

        fscanf(fp,"%d%d%d%d%d%d",&year,&month,&day,&h,&m,&s);
        printf("The Last excutation time is %dY %dM %dD %dH %dM %dS.\n",year,month,day,h,m,s);
        fclose(fp);
    }
}

/*---写入本次运行时的日期和时间---*/
void put_data(void)
{
    FILE *fp;
    time_t current =time(NULL);
    struct tm *timer = localtime(&current);

    if(fp=(fopen(data_file,"w"))==NULL)
    {
        printf("\aThe file open failure\n");
    }
    else
    {
        fprintf(fp,"%d %d %d %d %d %d\n",
        timer->tm_year+1900, timer->tm_mon+1,timer->tm_mday,
        timer->tm_hour,      timer->tm_min,  timer->tm_sec);
        fclose(fp);
    }   
}

int main(void)
{
    get_data();
    put_data();

    system("pause");
    return 0;
}