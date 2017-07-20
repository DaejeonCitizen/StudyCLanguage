#include <stdio.h>
#include <string.h>

int main(void)
{
	int i, len, zero = 1, num = 0;

	char str[50] = { 0, };
	fgets(str, sizeof(str), stdin);

	for (i = 0; str[i] != '\n'; i++); len = i;
	i--;

	while (1)
	{
		str[i] -= 48;
		i--;
		
		if (i < 0)
			break;
	}

	while (1)
	{
		if (len == 0)
			break;
		num += str[len-1]*zero;
		zero *= 10; len--;
	}

	printf("%d\n", num);

	return 0;

}
