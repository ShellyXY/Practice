#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;

	return;
}

void display(int array[], int maxlen)
{
	int i;

	for (i = 0; i < maxlen; i++)
	{
		printf("%-3d", array[i]);
	}
	printf("\n");

	return;
}

void BubbleSort(int A[], int n)
{
	int i, j;
	bool flag;
	for (i = 0; i < n - 1; i++)
	{
		flag = false;
		for (j = n - 1; j > i; j--)
		{
			if (A[j - 1] > A[j])
			{
				swap(&A[j - 1], &A[j]);
				flag = true;
			}
		}
		if (flag == false)
				return;
		}
	}

int main()
{
	int array[10] = { 12,35,25,16,34,23,49,45,17,31 };
	int maxlen = 10;

	printf("The Sequence before sort:\n");
	display(array, maxlen);

	BubbleSort(array,maxlen);

	printf("The Sequence after sort:\n");
	display(array, maxlen);

	system("pause");
	return 0;
}