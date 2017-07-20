#include <stdio.h>

void ChangeToHex(int);

int main(void)
{
	int num;
	
	printf("Input Decimal Number : ");
	scanf("%d", &num);
	ChangeToHex(num);

	return 0;
}

void ChangeToHex(int num)
{
	printf("%d => %#x", num, num);
}
