#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STR_JOB(A,B) printf("%s's job is %s.\n",A,B);
#define TEMPLEN 30

typedef struct
{
	char * name;
	char * job;
} Jobinfo;

void InputJobInfo(Jobinfo people[], int count)
{
	int i;
	Jobinfo temp;
	temp.name = (char *)malloc(sizeof(char) * 30);
	temp.job = (char *)malloc(sizeof(char) * 30);
	for (i = 0; i < count; i++)
	{
		printf("%d. Input name : ", i + 1);
		scanf_s("%s", temp.name, TEMPLEN);
		while (getchar() != '\n');
		printf("%d. Input job : ", i + 1);
		scanf_s("%s", temp.job, TEMPLEN);
		while (getchar() != '\n');
		people[i].name = (char *)malloc(sizeof(char) * strlen(temp.name) + 1);
		people[i].job = (char *)malloc(sizeof(char) * strlen(temp.job) + 1);
		strcpy_s(people[i].name, strlen(temp.name) + 1, temp.name);
		strcpy_s(people[i].job, strlen(temp.job) + 1, temp.job);
	}
	free(temp.name);
	free(temp.job);
}

void UnassignMemory(Jobinfo * info, int count)
{
	int i;
	for (i = 0; i < count; i++)
	{
		free(info[i].name);
		free(info[i].job);
	}
}

void ReadJobInfo(Jobinfo people[], int count)
{
	int i;

	for (i = 0; i < count; i++)
	{
		STR_JOB(people[i].name, people[i].job);
	}
}
int main(void)
{
	Jobinfo * job;
	int count;

	printf("How many input to job of peaple? : ");
	scanf_s("%d", &count);
	job = (Jobinfo *)malloc(sizeof(Jobinfo) * count);
	InputJobInfo(job, count);
	ReadJobInfo(job, count);
	UnassignMemory(job, count);
	
	return 0;
}
