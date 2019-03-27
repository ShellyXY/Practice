#include<stdio.h>

int main(void)
{
	FILE  *fp;

	fp = fopen("abc.txt","r");

	if (fp==NULL)
		printf("\acan not open\"abc\".\n");
	else
	{
		printf("\aSuccess open\"abc\".\n");
		fclose(fp);
	}

    system("pause");
	return 0;
	
}
