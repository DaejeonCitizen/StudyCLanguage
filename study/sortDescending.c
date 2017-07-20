#include <stdio.h>

void DesSort(int ary[], int len);

int main(void)
{
	int i;
	int arr[7];

	for (i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		printf("input int : ");
		scanf("%d", &arr[i]);
	}

	DesSort(arr, sizeof(arr) / sizeof(int));

	for (i = 0; i < sizeof(arr) / sizeof(int); i++)
		printf("%-8d", arr[i]);
	printf("\n");

	return 0;
}

void DesSort(int ary[], int len)
{
	int i, j, temp;

	for(i=0;i<len-1;i++) //Desecending array
		for(j=0;j<(len-i)-1;j++)
			if(ary[j] < ary[j + 1])
			{
				temp = ary[j];
				ary[j] = ary[j + 1];
				ary[j + 1] = temp;
			}
}
