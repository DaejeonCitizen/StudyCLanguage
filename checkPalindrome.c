#include <stdio.h>

int CheckPal(char * str)
{
	int len = 0, chef, cheb, check = 0, i;

	while (1)
	{
		if (str[len] == '\0')
			break;
		len++;
	}
	chef = 0, cheb = --len;
	for (i = 0; i < len / 2; i++)
	{
		if (str[chef+i] != str[cheb-i])
			check++;
	}
	return check;
}

int main(void)
{
	int check;
	char str[10];
	printf("Input word");
	scanf("%s", str);
	check = CheckPal(str);

	if (check == 0)
		printf("Right! palindrome\n");
	else
		printf("No, palindrome\n");

	return 0;

}
