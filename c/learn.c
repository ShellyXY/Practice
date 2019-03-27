#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define N 128
int main()
{
    char a[128];
    char UP[N],*U=UP;
    char LW[N],*L=LW;
    printf("Please input a string:");
    scanf("%s",a);
    int count = strlen(a);
    for(int i=0;i<count;i++)
    {
        if(isupper(a[i]))
        {
            *U=a[i];
            U++;
        }
        if(islower(a[i]))
        {
            *L=a[i];
            L++;
        }      
    }
    
    printf("The Lower character is %s\n",UP);
    printf("The Upper character is %s\n",LW);


    system("pause");
    return 0;

}