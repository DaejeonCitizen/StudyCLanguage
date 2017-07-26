#include <string.h>
#include <stdlib.h>

char * InsertBSN(char str[])
{
	char * temp = (char *)malloc(strlen(str) + 2);

	strcpy_s(temp, strlen(str) + 1, str);

	temp[strlen(str)] = '\n';
	temp[strlen(str) + 1] = 0;

	free(str);

	return temp;
}