#include<stdio.h>
#include<stdlib.h>
#define MAX 65535
int main()
{
    char str[MAX];
    char c;
    int Block=0;
    int Enter=1;
    FILE *fp=fopen("C:\\Users\\m1801\\Desktop\\test.txt","rt");
    if(fp==NULL)
    {
        printf("The File Open Failure.");
        return -1;
    }
    while((c=fgetc(fp))!=EOF)
    {
       if(c==' ')
       {
           Block++;
       }
       else if(c=='\n')
       {
           Enter++;
       }
    }
    
    printf("The file have %d words,%d prargraph",Block+Enter,Enter);
    system("pause");
    return 0;

}