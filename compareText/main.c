#include <stdio.h>
#include "include\comparecheck.h"

int main(int argc, char * argv[])
{
	FILE * fp1;
	FILE * fp2;

	fopen_s(&fp1, argv[1], "rt");
	fopen_s(&fp2, argv[2], "rt");

	if (CompareCheck(fp1, fp2) == 0)
		puts("Two files match!");
	else
		puts("Not matched file");

	return 0;
}