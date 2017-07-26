#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "phonenuminfo.h"
#include "removebsn.h"

Pnuminfo * LoadPn(Pnuminfo pbook[], int * recnt)
{
	int i;
	char fname[TEMPSIZE];
	FILE * fp;

	Pnuminfo temp = {
		temp.name = (char *)malloc(TEMPSIZE),
		temp.pnum = (char *)malloc(TEMPSIZE)
	};

	printf("Please enter file name for load : ");
	scanf_s("%s", fname, sizeof(fname));

	fopen_s(&fp, fname, "rt");

	for (i = 0; !feof(fp) ; i++)
	{
		if ((fgets(temp.name, TEMPSIZE, fp) == NULL) || (fgets(temp.pnum, TEMPSIZE, fp) == NULL))
			break;

		(*recnt)++;
		pbook = (Pnuminfo *)realloc(pbook, sizeof(Pnuminfo) * (*recnt));

		RemoveBSN(temp.name);
		RemoveBSN(temp.pnum);

		pbook[i].name = (char *)malloc(strlen(temp.name) + 1);
		pbook[i].pnum = (char *)malloc(strlen(temp.pnum) + 1);

		strcpy_s(pbook[i].name, strlen(temp.name) + 1, temp.name);
		strcpy_s(pbook[i].pnum, strlen(temp.pnum) + 1, temp.pnum);
	}

	if (feof(fp) != 0)
	{
		puts("\nLoad Complete !\n");
		fclose(fp);
		return pbook;
	}
	else
	{
		fclose(fp);
		puts("\nFailed load !\n");
		return pbook;
	}
}

