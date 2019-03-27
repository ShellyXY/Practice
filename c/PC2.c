#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

float hallen(float a,float b,float c)
{
    float p;
    float s;
    p=(a+b+c)/2;
    s=sqrt(p*(p-a)*(p-b)*(p-c));
    return s;
}

bool Judge(float a,float b,float c)
{
    if((a+b)>c&&(a+c)>b&&(b+c)>a)
    {
        return true;
    }
    else
    {
        return false;
    }    
}

int main()
{
    float a,b,c;         //定义所要输入三个值，分别代表三角形的三条边

    printf("Please input a =");      scanf("%f",&a); 
    while(a<0)
    {
        printf("please input a positive number");
        scanf("%f",&a); 
    }

    printf("Please input b =");      scanf("%f",&b); 
    while(b<0)
    {
        printf("please input a positive number");
        scanf("%f",&b); 
    }

    printf("Please input c =");      scanf("%f",&c); 
    while(c<0)
    {
        printf("please input a positive number");
        scanf("%f",&c);
    }

    if(Judge(a,b,c)==true)
    {
        printf("The area of the triangle is %f",hallen(a,b,c));
    }
    else
    {
        printf("This is not a triangle");
    }

    system("pause");
    return 0;
    
}