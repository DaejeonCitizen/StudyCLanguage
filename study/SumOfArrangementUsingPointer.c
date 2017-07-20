#include <stdio.h>

int main(void)
{
	int i, sum=0;
	int arr[5] = { 1,2,3,4,5 };
	int * ptr = &arr[4];

	for (i = 0; i < 5; i++)
		sum += *(ptr--);

	printf("result : %d \n", sum);

	return 0;
}
