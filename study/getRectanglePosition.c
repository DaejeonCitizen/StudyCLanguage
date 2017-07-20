#include <stdio.h>

typedef struct
{
	int xpos;
	int ypos;
} Point;

typedef struct
{
	Point vtx1;
	Point vtx2;
} Rect;

Rect InputPosition(void)
{
	Rect angle;
	printf("Input first x y: "); scanf("%d %d", &angle.vtx1.xpos, &angle.vtx1.ypos);
	printf("Input second x y: "); scanf("%d %d", &angle.vtx2.xpos, &angle.vtx2.ypos);

	return angle;
}

int OutputTract(Rect angle)
{
	return (angle.vtx1.xpos - angle.vtx2.xpos)*(angle.vtx1.ypos - angle.vtx2.ypos) > -1 ?
		(angle.vtx1.xpos - angle.vtx2.xpos)*(angle.vtx1.ypos - angle.vtx2.ypos) : (angle.vtx1.xpos - angle.vtx2.xpos)*(angle.vtx1.ypos - angle.vtx2.ypos)*-1;
}

void OutputFourPoint(Rect angle)
{
	Point vex1, vex2, vex3, vex4;

	if (angle.vtx1.ypos > angle.vtx2.ypos)
	{
		if (angle.vtx1.xpos > angle.vtx2.xpos)
		{
			vex2 = angle.vtx1, vex4 = angle.vtx2;
			vex1.xpos = vex4.xpos, vex1.ypos = vex2.ypos;
			vex3.xpos = vex2.xpos, vex3.ypos = vex4.ypos;
		}
		else
		{
			vex1 = angle.vtx1, vex3 = angle.vtx2;
			vex2.xpos = vex3.xpos, vex2.ypos = vex1.ypos;
			vex4.xpos = vex1.xpos, vex4.ypos = vex3.ypos;
		}
	}
	else
	{
		if (angle.vtx1.xpos < angle.vtx2.xpos)
		{
			vex4 = angle.vtx1, vex2 = angle.vtx2;
			vex1.xpos = vex4.xpos, vex1.ypos = vex2.ypos;
			vex3.xpos = vex2.xpos, vex3.ypos = vex4.ypos;
		}
		else
		{
			vex3 = angle.vtx1, vex1 = angle.vtx2;
			vex2.xpos = vex3.xpos, vex2.ypos = vex1.ypos;
			vex4.xpos = vex1.xpos, vex4.ypos = vex3.ypos;
		}
			
	}
	printf("\nPoint info\n");
	printf("%d, %-8d%d, %d", vex1.xpos, vex1.ypos, vex2.xpos, vex2.ypos);
	printf("\n\n\n\n");
	printf("%d, %-8d%d, %d\n", vex4.xpos, vex4.ypos, vex3.xpos, vex3.ypos);
}

int main(void)
{
	Rect ra = InputPosition();
	printf("Tract : %d\n", OutputTract(ra));
	OutputFourPoint(ra);

	return 0;
}
