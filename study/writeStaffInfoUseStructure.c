#include <stdio.h>
#include <string.h>

struct staff
{
	char name[20];
	int pay;
};

void RemoveN(char str[])
{
	str[strlen(str) - 1] = 0;
}
int main(void)
{
	struct staff staf;

	fputs("Input name: ", stdout);
	fgets(staf.name, sizeof(staf.name), stdin);
	RemoveN(staf.name);
	fputs("Input pay: ", stdout); scanf("%d", &staf.pay);

	printf("Name: %s\n", staf.name);
	printf("Pay: %d\n", staf.pay);

	return 0;
}
