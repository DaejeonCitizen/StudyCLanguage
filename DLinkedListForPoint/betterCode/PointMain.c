#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"
#include "Point.h"

int WhoIsPreced(LData d1, LData d2)
{
	return d1->xpos == d2->xpos ? (d1->ypos < d2->ypos ? 0 : 1) : (d1->xpos < d2->xpos ? 0 : 1);
}
int main(void)
{
	List list;
	Point compPos;
	Point * ppos;

	ListInit(&list);

	SetSortRule(&list, &WhoIsPreced);

	// insert four data  ///////////
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 1, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 1, 7);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 4, 3);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 1, 1);
	LInsert(&list, ppos);

	// output of save data ///////////
	printf("Current num of data: %d \n", LCount(&list));

	if (LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);

		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");

	// delete all data with xpos = 2  ///////////
	compPos.xpos = 2;
	compPos.ypos = 0;

	if (LFirst(&list, &ppos))
	{
		if (PointComp(ppos, &compPos) == 1)
		{
			ppos = LRemove(&list);
			free(ppos);
		}

		while (LNext(&list, &ppos))
		{
			if (PointComp(ppos, &compPos) == 1)
			{
				ppos = LRemove(&list);
				free(ppos);
			}
		}
	}

	// all data remain after delete  ///////////
	printf("Current num of data: %d \n", LCount(&list));

	if (LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);

		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");

	return 0;
}