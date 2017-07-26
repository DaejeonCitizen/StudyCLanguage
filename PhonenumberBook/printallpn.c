#include <stdio.h>
#include "phonenuminfo.h"

void PrintAllPn(Pnuminfo pbook[], int * recnt)
{
	if ((pbook->name == NULL) && (pbook->pnum == NULL))
	{
		puts("****No information to print\n");
		return;
	}

	int i;

	puts("\n****Print all information****\n");

	for (i = 0; i < *recnt; i++)
	{
		printf("Name : %-15s Phonenumber : %-15s\n", pbook[i].name, pbook[i].pnum);
	}

	puts("\n****Print Complete****\n");
}