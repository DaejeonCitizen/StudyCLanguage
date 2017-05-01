#include <stdio.h>

int Square(int);

int main(void)
{
	int num;
	printf("(2^n) n:");
	scanf("%d", &num);

	printf("2^%d = %d\n", num, Square(num));

	return 0;
}

int Square(int num)//repeat to input value using recursive
{
	if (num == 0)
		return 1;
	return Square(num - 1) * 2;
}
