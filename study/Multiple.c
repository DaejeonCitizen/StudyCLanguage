#include <stdio.h>

void Multiple(int, int);
int InputValue(void);

int main(void)
{
	int fir, sec;

	printf("Input two number : ");
	fir = InputValue();
	sec = InputValue();
	
	Multiple(fir, sec);

	return 0;
}

void Multiple(int n1,int n2) // get fir~sec googoodan
{
	int goo1, goo2, i;

	if (n1 > n2)
		goo1 = n2, goo2 = n1;
	else
		goo1 = n1, goo2 = n2;

	for (; goo1 <= goo2; goo1++)
		for (i = 1; i < 10; i++)
			printf("%2d X%2d = %2d\n", goo1, i, goo1*i);
}

int InputValue(void)
{
	int n;
	scanf("%d", &n);
	return n;
}
