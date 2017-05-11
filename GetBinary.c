#include <stdio.h>

void GetBinary(int num, int * bin, int * pcount)
{
	int i, rest;
	for (i = 0; num > 0; i++)
	{
		rest = num % 2;
		num = num / 2;
		if (rest == 1)
			bin[i] = 1;
		else
			bin[i] = 0;
		*pcount += 1;
	}
}

int main(void)
{
	int num, i, count = 0;
	int bin[64];
	printf("Input decimal number : ");
	scanf("%d", &num);

	GetBinary(num, bin, &count);
	count--;

	for (i = 0; i <= count; i++)
		printf("%d", bin[count-i]);
	printf("\n");

	return 0;
}
