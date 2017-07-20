#include <stdio.h>
#include <string.h>

const char * info[] = { "#NAME", "#PERSON NUMBER", "#PHONE NUMBER", "#FAVORITE FOOD", "#HOBBY" };

void WriteInfo(char * strt)
{
	int i;

	FILE * fp = fopen("mystory.txt", "wt");
	if (fp == NULL) {
		puts("failed file open");
		return;
	}

	for (i = 0; i < 3; i++)
	{
		printf("Input %s: ", info[i]);
		scanf("%s", strt);
		fputs(info[i], fp);
		fputs(": ", fp);
		fputs(strt, fp);
		fputs("\n", fp);
	}
	
	fclose(fp);
}

void AddInfo(char * strt)
{
	int i;

	FILE * fp = fopen("mystory.txt", "at");
	if (fp == NULL) {
		puts("failed open file");
		return;
	}

	for (i = 3; i < 5; i++)
	{
		printf("Input %s: ", info[i]);
		scanf("%s", strt);
		fputs(info[i], fp);
		fputs(": ", fp);
		fputs(strt, fp);
		fputs("\n", fp);
	}

	fclose(fp);
}

void ReadInfo(char * strt)
{
	int i = 0;
	FILE * fp = fopen("mystory.txt", "rt");
	if (fp == NULL) {
		puts("failed open file");
		return;
	}

	while(fgets(strt, sizeof(strt), fp) != NULL)
		printf("%s", strt);

	fclose(fp);
}
int main(void)
{
	int choc;
	char strt[50];
	
	printf("1.Write Info\n2.Add Info\n3.Read Info\nChoose What You Want? : ");
	scanf("%d", &choc);

	switch (choc)
	{
	case 1:
		WriteInfo(strt); break;
	case 2:
		AddInfo(strt); break;
	case 3:
		ReadInfo(strt); break;
	default:
		puts("error!"); return -1;
	}
	
	return 0;
}
