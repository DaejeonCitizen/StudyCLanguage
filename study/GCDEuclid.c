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
	return n1%n2 ? GCD(n2, n1%n2) : n2;
}

int InputValue(void)
{
	int n;
	scanf("%d", &n);
	return n;
}
