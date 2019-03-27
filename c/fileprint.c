#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp=fopen("C:\\Users\\m1801\\Desktop\\write.txt","wt+");
    if(fp==NULL)
    {
        printf("Open failure");
    }
    char str[128]={"Hello World"};
    fprintf(fp,str);

    system("pause");
    return 0;

}