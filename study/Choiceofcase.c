#include <stdio.h>
void ChoiceOfCase(int);

const int BREAD=700, SNACK=500, COLA=400;

int main(void)
{
	int money;

	printf("Input Money : ");
	scanf("%d", &money);

	ChoiceOfCase(money);
}

void ChoiceOfCase(int money)
{
	int bread, snack, cola;

	for (bread = 1; bread*BREAD < money; bread++)
		for (snack = 1; snack*SNACK < money; snack++)
			for (cola = 1; cola*COLA < money; cola++)
				if (BREAD*bread + SNACK*snack + COLA*cola == money)
					printf("Bread=%d, Snack=%d, Cola=%d\n", bread, snack, cola);
}
