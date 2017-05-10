#include <stdio.h>

void GetOddNum(int num[], int len)
{
	int i;

	printf("OddNumber : ");
	for (i = 0; i < len; i++)
		if (num[i] % 2 == 1)
			printf("%-8d",num[i]);
	printf("\n");
}

void GetEvenNum(int num[], int len)
{
	int i;

	printf("EveNumber : ");
	for (i = 0; i < len; i++)
		if (num[i] % 2 == 0)
			printf("%-8d", num[i]);
	printf("\n");
}

int main(void)
{
	int len, i;
	int arr[10];

	len = sizeof(arr) / sizeof(int);
	
	for (i = 0; i < len; i++)
	{
		printf("input value : ");
		scanf("%d", &arr[i]);
	}

	GetOddNum(arr, len);
	GetEvenNum(arr, len);

	return 0;
}
