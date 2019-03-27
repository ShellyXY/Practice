#include <stdio.h>  
  
int main()  
{  
    int a[10]={0};
    int i;
    FILE *fpRead=fopen("input.txt","r");  //其中"r"是表示 读
    if(fpRead==NULL)  
    {  
        return 0;  
    }  
    for( i=0;i<10;i++)  
    {  
        fscanf(fpRead,"%d ",&a[i]);  
        printf("%d ",a[i]);
        
    }  
    printf("\n");
    system("pause");
    return 1;  
}