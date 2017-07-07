#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i = 0;
	int len = 5;
	int * narr = (int *)malloc(sizeof(int) * 5);

	while (1)
	{
		if (i == 5 || (i - 5) % 3 == 0)
		{
			len += 3;
			narr = realloc(narr, sizeof(int) * len);
			if (narr == NULL)
				puts("faild run realloc function");
		}
		printf("Input [%3d] number : ", i + 1);
		scanf("%d", &narr[i]);
		if (narr[i] == -1)
			break;
		i++;
	}

	for (i = 0; narr[i] != -1; i++)
		printf("[%3d] number : %d\n", i + 1, narr[i]);

	free(narr);

	return 0;
}
