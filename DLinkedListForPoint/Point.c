#include <stdio.h>
#include "Point.h"
#include "DLinkedList.h"

void SetPointPos(Point * ppos, int n1, int n2)
{
	ppos->xpos = n1;
	ppos->ypos = n2;
}

void ShowPointPos(Point * ppos)
{
	printf("X : %-4d Y : %-4d\n", ppos->xpos, ppos->ypos);
}

int PointComp(Point * ppos, Point * cpos)
{
	return (ppos->xpos == cpos->xpos) || (ppos->ypos == cpos->ypos) ? TRUE : FALSE;
}