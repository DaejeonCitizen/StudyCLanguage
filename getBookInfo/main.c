#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bookinfo.h"
#include "inputbookinfo.h"

int main(void)
{
	Bookinfo * book;
	int i;
	int count;

	printf("How many insert book info? : "); scanf_s("%d", &count);
	while (getchar() != '\n');

	book = (Bookinfo *)malloc(sizeof(Bookinfo) * count);

	Inputbookinfo(book, count);
	
	for (i = 0; i < count; i++)
	{
		printf("----%d.Book info----\n", i + 1);
		printf("Title: %s\n", book[i].title);
		printf("Writer: %s\n", book[i].writer);
		printf("Page: %d\n", *book[i].page);
	}

	return 0;
}
