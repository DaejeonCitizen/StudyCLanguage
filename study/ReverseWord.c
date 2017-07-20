#include <stdio.h>

int main(void)
{
	char str[30];

	int len, temp, i;

	printf("input word : ");
	scanf("%s", str);

	for (len = 0; str[len] != '\0'; len++);
	
	for (i = 0; i < len / 2; i++)
	{
		temp = str[i];
		str[i] = str[(len-i)-1];
		str[(len-i)-1] = temp;
	}
	
	printf("%s", str);

	return 0;
}
