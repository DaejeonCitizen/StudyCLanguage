#ifndef __POINT_H__
#define __POINT_H__

typedef struct _point
{
	int xpos;
	int ypos;
} Point;

void SetPointPos(Point * ppos, int n1, int n2);
void ShowPointPos(Point * ppos);
int PointComp(Point * ppos, Point * cpos);

#endif