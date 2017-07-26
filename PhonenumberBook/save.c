#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "phonenuminfo.h"
#include "insertbsn.h"

Pnuminfo * SavePn(Pnuminfo pbook[], int * recnt)
{
	char fname[TEMPSIZE];
	int i;
	
	FILE * fp;

	printf("Please enter file name for save : ");
	scanf_s("%s", fname,sizeof(fname));
	while (getchar() != '\n');

	fopen_s(&fp, fname, "wt");

	for (i = 0; i < *recnt; i++)
	{
		pbook[i].name = InsertBSN(pbook[i].name);
		pbook[i].pnum = InsertBSN(pbook[i].pnum);

		fputs(pbook[i].name, fp);
		fputs(pbook[i].pnum, fp);
	}

	puts("\n****Save Complete\n");

	*recnt = 0;

	fclose(fp);

	for (i = 0; i < *recnt; i++)
	{
		free(pbook[i].name);
		free(pbook[i].pnum);
	}
	free(pbook);

	Pnuminfo * repbook = (Pnuminfo *)malloc(sizeof(Pnuminfo));
	repbook->name = NULL;
	repbook->pnum = NULL;
	return repbook;
}