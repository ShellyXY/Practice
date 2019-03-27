#include<time.h>
#include<stdio.h>
int main()
{
    time_t current = time(NULL);
    struct tm *timer = localtime(&current); /*定义了一个指向tm类型的指针timer,localtiem函数可以将日历时间转换为分解时间*/
    char *wday_name[] = {"Sunday","Monday","Tuesday","Wensday","Thursday","Friday","Saturday"};  
    printf("The Current date and time is Year:%d Month:%d Day:%d Hour:(%s)%d Minute:%d Second:%d.\n",
    timer->tm_year+1900,
    timer->tm_mon+1,
    timer->tm_mday,
    wday_name[timer->tm_mday],
    timer->tm_hour,
    timer->tm_min,
    timer->tm_sec
    );
    
    system("pause");
    return 0;
}