#include <stdio.h>

int main(void)
{
	int i, temp, arrs;
	int arr[6] = { 1,2,3,4,5,6 };
	int * ptrf = &arr[0];
	int * ptrr = &arr[5];
	
	arrs = sizeof(arr) / sizeof(int);

	for (i = 0; i < arrs / 2; i++)
	{
		temp = *(ptrf + i);
		*(ptrf+i) = *(ptrr - i);
		*(ptrr-i) = temp;
	}

	for (i = 0; i < arrs; i++)
		printf("%-2d", arr[i]);

	return 0;

}
