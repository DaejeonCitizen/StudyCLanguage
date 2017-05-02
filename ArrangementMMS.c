#include <stdio.h>

int main(void)
{
	int num[5];
	int i;
	int max = 0, min = 0, sum = 0;

	printf("input five values : ");
	for (i = 0; i < 5; i++)
		scanf("%d", &num[i]);

	for (i = 0; i < 5; i++)
	{
		max = num[i] > max ? num[i] : max;
		if (min == 0)
			min = max;
		min = num[i] < min ? num[i] : min;
	}
	for (i = 0; i < 5; i++)
		sum += num[i];

	printf("Max : %d\n", max);
	printf("Min : %d\n", min);
	printf("Sum : %d\n", sum);

	return 0;
}
