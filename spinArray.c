#include <stdio.h>

void InputArrRegular(int ar[][4], int column)
{
	int i, j, c = 1;
		for (i = 0; i < column; i++)
			for (j = 0; j < 4; j++)
				ar[i][j] = c, c++;
		
}

void ShowArr(int ar[][4], int column)
{
	int i, j;
	for (i = 0; i < column; i++)
	{
		for (j = 0; j < 4; j++)
			printf("%-4d", ar[i][j]);
		printf("\n");
	}
	printf("\n");
}

void MoveElement(int ar[][4], int column, void(*Show)(int far[][4], int col))
{
	int i, j;
	int tar[4][4] = {0, };

	for (i = 0; i < column; i++)
		for (j = 0; j < 4; j++)
			tar[i][j] = ar[i][j];

	for (i = 0; i < column; i++)
		for (j = 0; j < 4; j++)
			ar[j][3 - i] = tar[i][j];
	Show(ar, column);

	for (i = 0; i < column; i++)
		for (j = 0; j < 4; j++)
			ar[3-i][3-j] = tar[i][j];
	Show(ar, column);

	for (i = 0; i < column; i++)
		for (j = 0; j < 4; j++)
			ar[3 - j][i] = tar[i][j];
	Show(ar, column);
}

int main(void)
{
	int arr[4][4];
	int column = sizeof(arr) / sizeof(arr[0]);
	InputArrRegular(arr, column);
	ShowArr(arr, column);
	MoveElement(arr, column, ShowArr);

	return 0;
}
