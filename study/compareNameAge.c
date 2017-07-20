#include <stdio.h>
#include <string.h>

void RemoveN(char str[])
{
	int len = strlen(str);
	str[len - 1] = 0;
}

void CopyToEachPart(char info[], char name[], char age[])
{
	int i, j = 0;

	for (i = 0; info[i] != ' '; i++);
	strncpy(name, info, i + 1);
	name[i + 1] = 0;

	for (i += 2; info[i] != 0; i++)
		age[j] = info[i]; j++;
	age[j] = 0;
}
int main(void)
{
	char name1[20];
	char name2[20];
	char age1[5];
	char age2[5];
	char info1[25];
	char info2[25];

	fputs("First input name and age : ", stdout);
	fgets(info1, sizeof(info1), stdin);
	RemoveN(info1);

	fputs("Second input name and age : ", stdout);
	fgets(info2, sizeof(info2), stdin);
	RemoveN(info2);
	
	CopyToEachPart(info1, name1, age1);
	CopyToEachPart(info2, name2, age2);

	if (!strcmp(name1, name2))
		puts("Same name");
	else
		puts("Name is not same");

	if (!strcmp(age1, age2))
		puts("Same age");
	else
		puts("Age is not same");

	return 0;

}
