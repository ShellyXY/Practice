#include<stdio.h>
int main(int argc,char const *argv)
{
    printf("%s:%d\n",__FILE__,__LINE__);
    printf("%s:%d\n",__DATE__,__TIME__);

    system("pause");
    return 0;
}