#include <stdio.h>

int main(void)
{
	int dan, mul, i = 0, j = 0;
	int arr[3][9];

	for (dan = 2; dan <= 4; dan++)
	{
		j = 0;
		for (mul = 1; mul <= 9; mul++)
		{
			arr[i][j] = dan*mul;
			j++;
		}
		i++;
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 9; j++)
			printf("%-2d ", arr[i][j]);
		printf("\n");
	}

	return 0;
}
