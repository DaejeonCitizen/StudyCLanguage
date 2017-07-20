#include <stdio.h>

struct person
{
	char name[20];
	char phone[20];
	int age;
};

int main(void)
{
	struct person arr[3];
	int i;

	for (i = 0; i < 3; i++)
	{
		fputs("Input name, phone number, age: ", stdout);
		scanf("%s %s %d", arr[i].name, arr[i].phone, &arr[i].age);
	}

	for (i = 0; i < 3; i++)
		printf("%s %s %d\n", arr[i].name, arr[i].phone, arr[i].age);

	return 0;
}
