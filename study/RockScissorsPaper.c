#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int win, draw, lose;
	win = draw = lose = 0;

	srand((int)time(NULL));
	char *srp[3] = { "바위","가위","보" };
	char *oc[3] = { "이겼습니다.","비겼습니다.","졌습니다." };
	printf("%s는 1 / %s는 2 / %s는 3\n", srp[0], srp[1], srp[2]);

	while (1)
	{
		int me, com, res;

		printf("무엇을 내시겠습니까? ");
		scanf("%d", &me), me--;

		com = rand() % 3;

		printf("당신은 %s를 선택, 컴퓨터는 %s를 선택, ", srp[me], srp[com]);
		// another person code
		if (me == com)
			res = 1, draw++;
		else if (me == 0 && com == 2 || me == 1 && com == 0 || me == 2 && com == 1)
			res = 2, lose++;
		else
			res = 0, win++;
		/* my code
		if (me == 0)
		{
			if (com == 0)
				res = 1, draw++;
			else if (com == 1)
				res = 0, win++;
			else
				res = 2, lose;
		}
		else if (me == 1)
		{

			if (com == 0)
				res = 2, lose++;
			else if (com == 1)
				res = 1, draw++;
			else
				res = 0, win++;
		}
		else
		{
			if (com == 0)
				res = 0, win++;
			else if (com == 1)
				res = 2, lose++;
			else
				res = 1, draw++;
		}
		*/

		
		printf("%s\n\n", oc[res]);
		if (res == 2)
			break;
	}
	printf("게임의 결과 : %d승 %d무\n", win, draw);
}
