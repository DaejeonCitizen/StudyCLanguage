#include <stdio.h>

void Swap3(int * n1, int * n2, int * n3)
{
	int temp = *n1;
	*n1 = *n3;
	*n3 = *n2;
	*n2 = temp;
}

int main(void)
{
	int n1 = 11, n2 = 22, n3 = 33;

	Swap3(&n1, &n2, &n3);

	printf("%d %d %d", n1, n2, n3);

	return 0;
}
