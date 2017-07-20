#include <stdio.h>

void ChaingeSecToHMC(int);
int InputValue(void);

int main(void)
{
	int sec;
	
	printf("input sec : ");
	sec = InputValue();
	
	ChaingeSecToHMC(sec);

	return 0;
}

void ChaingeSecToHMC(int sec)
{
	int h = 0, m = 0;
	
	if (sec < 60)
		sec = sec;
	else if (sec < 3600)
		m = sec / 60, sec = sec % 60;
	else
		h = sec / 3600, m = (sec % 3600) / 60, sec = (sec % 3600) % 60;

	printf("%d : %d : %d\n", h, m, sec);
}

int InputValue(void)
{
	int n;
	scanf("%d", &n);
	return n;
}
