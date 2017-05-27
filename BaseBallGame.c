#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Ball(int pac[], int pau, int * b)
{
	int i;

	for (i = 0; i < 3; i++)
		if (pau == pac[i])
			(*b)++;
}

void StrikeBall(int pac[], int pau[])
{
	int i, s, b, c;
	i = s = b = c = 0;

	while (1)
	{
		printf("Select 3 number : \n");
		scanf("%d %d %d", &pau[0], &pau[1], &pau[2]);

		for (i = 0; i < 3; i++)
		{
			pac[i] == pau[i] ? s++ : Ball(pac, pau[i], &b);
		}
		c++;

		printf("%d번째 도전 결과 : %dStrike, %dBall\n\n", c, s, b);
		
		if (s == 3)
			break;
		else
			b = s = 0;

	}
	printf("Game over!\n");
	
}


int main(void)
{
	int arrc[3] = { 0, };
	int arru[3] = { 0, };
	int i;

	srand((int)time(NULL));

	for (i = 0; i < 3; i++)
		arrc[i] = rand() % 10;

	printf("Game start!\n");

	StrikeBall(arrc, arru);

}
