#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "include\bookinfo.h"
#include "include\removebsn.h"
#define TEMPSIZE 50

void Inputbookinfo(Bookinfo * book, int count)
{
	int i;
	Bookinfo booktemp = {
		booktemp.title = (char *)malloc(sizeof(char) * 50),
		booktemp.writer = (char *)malloc(sizeof(char) * 50),
		booktemp.page = (int *)malloc(sizeof(int))
	};

	for (i = 0; i < count; i++)
	{
		printf("----%d¹øÂ° Ã¥ Á¤º¸ ÀÔ·Â----\n", i + 1);

		printf("Insert title: ");
		fgets(booktemp.title, TEMPSIZE, stdin);
		RemoveBSN(booktemp.title);

		printf("Insert writer: ");
		fgets(booktemp.writer, TEMPSIZE, stdin);
		RemoveBSN(booktemp.writer);

		printf("Insert page: ");
		scanf_s("%d", booktemp.page);
		getchar();

		book[i].title = (char *)malloc(sizeof(char) * strlen(booktemp.title) + 1);
		book[i].writer = (char *)malloc(sizeof(char) * strlen(booktemp.writer) + 1);
		book[i].page = (int *)malloc(sizeof(int));


		strcpy_s(book[i].title, strlen(booktemp.title) + 1, booktemp.title);
		strcpy_s(book[i].writer, strlen(booktemp.writer) + 1, booktemp.writer);
		*book[i].page = *booktemp.page;
	}
	
	free(booktemp.title);
	free(booktemp.writer);
	free(booktemp.age);
}
