#include<time.h>
#include<stdio.h>

int main(void)
{
    FILE *fp;
    time_t current = time(NULL);               /*当前日历时间*/
    struct tm *timer =localtime(&current);     /*分解时间（当地时间）*/

    if((fp=fopen("dt_dat","w"))==NULL)
    {
        printf("\aFile Open failure.\n");
    }
    else
    {
        printf("The current time and date.\n");
        fprintf(fp,"%d %d %d %d %d %d\n",
        timer->tm_year+1900, timer->tm_mon+1, timer->tm_mday,
        timer->tm_hour,      timer->tm_min,   timer->tm_sec);
        fclose(fp);
    }
    
    system("pause");
    return 0;

}