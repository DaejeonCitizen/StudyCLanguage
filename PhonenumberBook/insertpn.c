#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "removebsn.h"
#include "phonenuminfo.h"

Pnuminfo * InsertPn(Pnuminfo pbook[], int * recnt)
{
	Pnuminfo temp = {
	temp.name = (char *)malloc(TEMPSIZE),
	temp.pnum = (char *)malloc(TEMPSIZE)
	}; //temp for malloc

	(*recnt)++; //add count for realloc

	pbook = (Pnuminfo *)realloc(pbook, sizeof(Pnuminfo) * (*recnt)); // additional struct arr
	if (pbook == NULL) {
		puts("\nfailed realloc !\n");
		return NULL;
	}

	printf("Insert name : ");
	fgets(temp.name, TEMPSIZE, stdin); // get name

	printf("Insert phonenumber : ");
	fgets(temp.pnum, TEMPSIZE, stdin); // get phonenumber
	
	RemoveBSN(temp.name); //remove \n
	RemoveBSN(temp.pnum);

	pbook[(*recnt) - 1].name = (char *)malloc(sizeof(char) * strlen(temp.name) + 1); // fitable alloc
	pbook[(*recnt) - 1].pnum = (char *)malloc(sizeof(char) * strlen(temp.pnum) + 1);

	strcpy_s(pbook[(*recnt) - 1].name, strlen(temp.name) + 1, temp.name); // copy from temp to pbook
	strcpy_s(pbook[(*recnt) - 1].pnum, strlen(temp.pnum) + 1, temp.pnum);

	puts("\n****Insert Complete\n");
	
	free(temp.name);
	free(temp.pnum);

	return pbook;
}