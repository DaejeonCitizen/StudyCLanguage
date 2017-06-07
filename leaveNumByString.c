#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int i, sum = 0;
	char str[50];

	fputs("Intput string :", stdout);
	fgets(str, sizeof(str), stdin);

	for (i = 0; str[i] != '\n'; i++)
	{
		if (str[i] > 47 && str[i] < 58)
			sum += str[i] - 48;
	}

	printf("%d\n", sum);

	return 0;
}
