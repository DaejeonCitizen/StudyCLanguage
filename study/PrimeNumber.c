#include <stdio.h>

void PrimeNumber(int)

int main(void)
{
	int count;
	printf("Number of PrimeNumber : ");
	scanf("%d", &count);
	PrimeNumber(count);
}

void PrimeNumber(int count) // get primenumber
{
	int n1 = 2, n2, i;

	for (i = 1; count >= i; n1++)
	{
		for (n2 = 2; n1 > n2; n2++)
		{
			if (n1%n2 == 0)
				break;
		}
		if (n1 == n2)
			printf("%d\n", n1), i++;
	}
}
