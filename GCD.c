#include <stdio.h>

int GCD(int, int);
int InputValue(void);

int main(void)
{
	int n1, n2;

	printf("Input two values : ");
	n1 = InputValue();
	n2 = InputValue();

	printf("Result : %d\n", GCD(n1, n2));

	return 0;
}

int GCD(int n1, int n2)
{
	int gcd, a, b;
	
	for (gcd = n1; gcd <= n1; gcd--)
	{
		a = n1%gcd, b = n2%gcd;
		if (a + b == 0)
			return gcd;
	}
}

int InputValue(void)
{
	int n;
	scanf("%d", &n);
	return n;
}
