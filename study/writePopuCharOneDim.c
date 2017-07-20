#include <stdio.h>

void writeChart(int chart[])
{
	int i, j;

	for (i = 0; i < 4; i++)
		for (j = 0; j < 2; j++)
		{
			printf("%d0%d호의 거주인원을 입력 해주세요 : ", i + 1, j + 1);
			scanf("%d", &chart[i * 2 + j]);
		}
}

void showChart(int chart[])
{
	int i, j;

	for (i = 0; i < 4; i++)
		for (j = 0; j < 2; j++)
			printf("%d0%d호 거주인원 : %d\n", i + 1, j + 1, chart[i * 2 + j]);
	printf("\n");
	
	for (i = 0; i < 4; i++)
	{
		int popu = 0;
		for (j = 0; j < 2; j++)
			popu += chart[i * 2 + j];
		printf("%d층 총 거주 인원 : %d명\n", i + 1, popu);
	}
}

int main(void)
{
	int arr[8];
	
	writeChart(arr);
	showChart(arr);

	return 0;
}
