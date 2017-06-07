#include <stdio.h>
#include <string.h>

void Remove(char str[])
{
	int len = strlen(str);
	str[len - 1] = 0;
}
int main(void)
{
	int len;
	char str1[20];
	char str2[20];
	char str3[40];

	fputs("Input first string : ", stdout);
	fgets(str1, sizeof(str1), stdin);
	Remove(str1);

	fputs("Input second string : ", stdout);
	fgets(str2, sizeof(str2), stdin);
	Remove(str2);

	len = strlen(str1);
	strcpy(str3, str1);
	str3[len] = 0;
	strcat(str3, str2);

	printf("%s\n", str3);

	return 0;
}
