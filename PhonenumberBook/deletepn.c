#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "phonenuminfo.h"
#include "removebsn.h"

Pnuminfo * DeletePn(Pnuminfo pbook[], int * recnt)
{
	int i;

	char sch[TEMPSIZE];// search string temp

	printf("Please enter name or phonenumber to delete : "); // input for search
	fgets(sch, sizeof(sch), stdin);
	RemoveBSN(sch);

	for (i = 0; i < *recnt; i++)
	{
		if ((!strcmp(pbook[i].name, sch)) || (!strcmp(pbook[i].pnum, sch))) //search name or phonenumber
		{
			pbook[i].name[0] = 0;
			pbook[i].pnum[0] = 0;
			break; // break and keeping [i]value for forward sort
		}

		if(i==((*recnt) - 1)) // not find name or phonenumber
		{
			puts("\nError! Nothing entered.. return to menu\n");
			return pbook;
		}
	}

	if ((i + 1) < *recnt) // check deleted element is the last element..
	{
		for (; i < (*recnt) - 1; i++)
		{
			pbook[i].name = (char *)realloc(pbook[i].name, strlen(pbook[i + 1].name) + 1); //stretch string alloc
			pbook[i].pnum = (char *)realloc(pbook[i].pnum, strlen(pbook[i + 1].pnum) + 1);
			
			strcpy_s(pbook[i].name, strlen(pbook[i + 1].name) + 1, pbook[i + 1].name); // right in front to copy
			strcpy_s(pbook[i].pnum, strlen(pbook[i + 1].pnum) + 1, pbook[i + 1].pnum);
		}
		(*recnt)--; // info count -1

		free(pbook[(*recnt)].name);
		free(pbook[(*recnt)].pnum);

		pbook = (Pnuminfo *)realloc(pbook, sizeof(Pnuminfo) * (*recnt));// resizing Pnuminfo arr
	}
	else // deleted element is the last element!
	{
		(*recnt)--;

		free(pbook[(*recnt)].name);
		free(pbook[(*recnt)].pnum);
		pbook = (Pnuminfo *)realloc(pbook, sizeof(Pnuminfo) * (*recnt)); // resizing Pnuminfo arr
	}

	puts("\n****Delete Complete!\n");

	return pbook;
}