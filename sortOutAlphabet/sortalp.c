#include <stdio.h>

int SortOutAlp(FILE * fp)
{
	int count = 0;
	char alp;
	char check;
	
	alp = fgetc(fp);
	if (alp == 'A' || alp == 'a' || alp == 'P' || alp == 'p')
		count++;

	while (1)
	{
		alp = fgetc(fp);
		if (alp == ' ' || alp == '\n' || alp == '\t')
		{
			check = fgetc(fp);
			if (check == 'A' || check == 'a' || check == 'P' || check == 'p')
				count++;

			fseek(fp, -1, SEEK_CUR);
		}

		if (feof(fp) != 0)
			return count;
	}
}