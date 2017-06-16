#include <stdio.h>

typedef struct
{
	int xpos;
	int ypos;
} Point;

void SwapPoint(Point * ppos1, Point * ppos2)
{
	printf("Swaping...\n\n");
	Point temp;
	temp = (*ppos1);
	(*ppos1) = (*ppos2);
	(*ppos2) = temp;
}

int main(void)
{
	Point pos1 = { 2, 4 };
	Point pos2 = { 5, 7 };

	printf("pos1: %d %d\n", pos1.xpos, pos1.ypos);
	printf("pos2: %d %d\n\n", pos2.xpos, pos2.ypos);
	
	SwapPoint(&pos1, &pos2);

	printf("pos1: %d %d\n", pos1.xpos, pos1.ypos);
	printf("pos2: %d %d\n", pos2.xpos, pos2.ypos);

	return 0;
}
