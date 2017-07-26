#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "phonenuminfo.h"

int main(void)
{
	int i;
	int cho;
	int recnt = 0;
	Pnuminfo * info = (Pnuminfo *)malloc(sizeof(Pnuminfo));
	if (info == NULL) {
		puts("failed malloc !");
		return -1;
	}

	info->name = NULL;
	info->pnum = NULL;
	
	while (1)
	{
		puts("****MENU****");
		puts("1. Insert");
		puts("2. Delete");
		puts("3. Search");
		puts("4. Print All");
		puts("5. Save");
		puts("6. Load");
		puts("7. Exit");
		printf("Select Menu : "); scanf_s("%d", &cho);
		while (getchar() != '\n');
		puts("");

		switch (cho)
		{
		case 1:
			info = InsertPn(info, &recnt);
			if (info == NULL) {
				puts("\nFailed insert !\n");
			}
			break;
		case 2:
			info = DeletePn(info, &recnt);
			if (info == NULL) {
				puts("\nFailed delete !\n");
			}
			break;
		case 3:
			SearchPn(info, &recnt); break;
		case 4:
			PrintAllPn(info, &recnt); break;
		case 5:
			info = SavePn(info, &recnt); break;
		case 6:
			info = LoadPn(info, &recnt); break;
		case 7:
			for (i = 0; i < recnt; i++)
			{
				free(info[i].name);
				free(info[i].pnum);
			}
			free(info);
			return 0;
		default:
			puts("\nEntered wrong select !\n");
		}
	}
}