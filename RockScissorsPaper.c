#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int win, draw, lose;
	win = draw = lose = 0;

	srand((int)time(NULL));
	char *srp[3] = { "가위","바위","보" };
	char *oc[3] = { "이겼습니다.","비겼습니다.","졌습니다." };
	printf("%s는 1 / %s는 2 / %s는 3\n", srp[0], srp[1], srp[2]);

	while (1)
	{
		int me, com, res;

		printf("무엇을 내시겠습니까? ");
		scanf("%d", &me);
		com = rand() % 4;
		printf("당신은 %s를 선택, 컴퓨터는 %s를 선택, ", srp[me - 1], srp[com - 1]);

		if (me > com)
			res = 0, win++;
		else if (me == com)
			res = 1, draw++;
		else
			res = 2, lose++;

		printf("%s\n", oc[res]);

		if (lose != 0)
			break;
	}
	printf("게임의 결과 : %d승 %d무\n", win, draw);
}
