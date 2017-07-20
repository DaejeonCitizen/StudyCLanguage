#include <stdio.h>

int main(void)
{
	char str[50];
	int count;

	printf("input word : ");
	scanf("%s", str);
	for (count = 1; str[count] != '\0'; count++);
	printf("word length : %d", count);

	return 0;

}
