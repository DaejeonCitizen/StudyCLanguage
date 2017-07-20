#include <stdio.h>

int main(void)
{
	char str[50];
	int i = 0, c;
	int maxa=0;

	printf("input word : ");
	scanf("%s", str);

	while (str[i] != '\0')
		i++;

	for (c = 0; c < i; c++)
		maxa = maxa < str[c] ? str[c] : maxa;

	printf("%c", maxa);
}
