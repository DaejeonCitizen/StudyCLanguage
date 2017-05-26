#include <stdio.h>

void ShowArr(int ar[][50], int n)
{
	int i, j;

	for (i = 1; i < n+1; i++)
	{
		for (j = 1; j < n+1; j++)
			printf("%-4d", ar[i][j]);
		printf("\n");
	}
}

void SnailArray(int ar[][50], int n)
{
	int i, j, f, b, t, c = 1;

	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			ar[i][j] = -1;
	
	f = b = t = 0;
	i = 1, j = 0;
	
	while (c != n*n+1)
	{
		if (t == 0)
			f = 0, b = 1;
		else if (t == 1)
			f = 1, b = 0;
		else if (t == 2)
			f = 0, b = -1;
		else if (t == 3)
			f = -1, b = 0;

		while (1)
		{
			i += (f), j += (b);
			if (ar[i][j] != -1)
				break;
			ar[i][j] = c, c++;
		}
		i -= (f), j -= (b);

		t++;
		t = t % 4;
	}
	
}

int main(void)
{
	int arr[50][50] = { 0, };
	int n = 0;
	printf("n x n의 달팽이배열을 출력합니다 n의 값 입력");
	scanf("%d", &n);
	SnailArray(arr, n);
	ShowArr(arr, n);

	return 0;
}
