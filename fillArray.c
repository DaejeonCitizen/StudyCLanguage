#include <stdio.h>

void FillInArrByOdd(int num, int * arr)
{
	static int codd = 0;
	arr[codd] = num;
	codd++;
}

void FillInArrByEven(int num, int * arr)
{
	static int ceven = 9;
	arr[ceven] = num;
	ceven--;
}

int main(void)
{
	int num, i;
	int arr[10];

	for (i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		printf("input : ");
		scanf("%d", &num);
		if (num % 2 == 1)
			FillInArrByOdd(num, arr);
		else
			FillInArrByEven(num, arr);
	}

	for (i = 0; i < sizeof(arr) / sizeof(int); i++)
		printf("%-5d", arr[i]);

	return 0;

}
