#include<stdio.h>
int main()
{
    int i,a[100],n,max;
    scanf("%d",&n);
    if(n>0)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        i=0;
        max=a[0];
        while(i<n)
        {
            if(max<a[i])
            {
                max=a[i];
            }
            i++;
        }
        printf("%d\n",max);
    }    
    return 0;
}