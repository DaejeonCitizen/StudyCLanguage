#include <stdio.h>
#include <string.h>
#include "removebsn.h"
#include "phonenuminfo.h"

void SearchPn(Pnuminfo pbook[], int * recnt)
{
	int i;
	char sch[TEMPSIZE]; // string temp for search

	printf("Please enter name or phonenumber to search : "); //get string for search
	fgets(sch, sizeof(sch), stdin);
	RemoveBSN(sch);

	for (i = 0; i < *recnt; i++)
	{
		if ((!strcmp(pbook[i].name, sch)) || (!strcmp(pbook[i].pnum, sch))) // search name or phonenumber
		{
			printf("Name : %15s Phonenumber : %15s\n", pbook[i].name, pbook[i].pnum); //print search info
			puts("\n****Printf Complete\n");
			return;
		}
	}
	
	puts("\nInformation is not found!\n"); // not found name or phonenumber
	return;
}