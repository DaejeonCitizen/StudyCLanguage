#include <stdio.h>

int Square(int);

int main(void)
{
	int num;
	
	printf("(2^k<=n)  n:");
	scanf("%d", &num);

	printf("2^%d<=%d", Square(num), num);

	return 0;
}

int Square(int num) //2^k=n, return k
{
	int sum = 1, i = 0;
	while(1)
	{
		sum = sum * 2;

		if (sum > num)
			return i;

		i++;
		
	}

}
