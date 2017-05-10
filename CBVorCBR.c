#include <stdio.h>

void SquareByReference(int * pnum)
{
	*pnum *= *pnum;
}

int SquareByValue(int num)
{
	return num *= num;
}

int main(void)
{
	int num;
	scanf("%d", &num);

	printf("Square of %d = %d (call by value)\n", num, SquareByValue(num));
	
	SquareByReference(&num);
	printf("use call by reference = %d\n", num);

	return 0;
}
