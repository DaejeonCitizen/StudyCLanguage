#include <stdio.h>

int CompareCheck(FILE * fp1, FILE * fp2)
{
	char tg1, tg2;
	
	while (1)
	{
		tg1 = fgetc(fp1);
		tg2 = fgetc(fp2);
		
		if (tg1 != tg2)
			return -1;
		
		if ((feof(fp1) != 0) || (feof(fp2) != 0))
			return 0;
	}
}