#include <stdio.h>
#include "include\sortalp.h"

int main(void)
{
	FILE * fp;
	
	fopen_s(&fp, "string.txt", "rt");
	if (fp == NULL) {
		puts("failed file open!");
		return -1;
	}
	
	printf("Count of 'A' or 'P' : %d", SortOutAlp(fp));

	return 0;
}