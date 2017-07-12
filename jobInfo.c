#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STR_JOB(A,B) #A "'s job is " #B

typedef struct
{
	char * name;
	char * job;
} Jobinfo;

void InputJobInfo(Jobinfo people[], int count)
{
	int i;
	Jobinfo temp = { (char *)malloc(sizeof(char) * 30), (char *)malloc(sizeof(char) * 30) };

	for (i = 0; i < count; i++)
	{
		printf("%d. Input name : ", i + 1), scanf_s("%s", temp.name,sizeof(temp.name));
		while (getchar() != '\n');
		printf("%d. Input job : ", i + 1), scanf_s("%s", temp.job, sizeof(temp.job));
		while (getchar() != '\n');
		people[i].name = (char *)malloc(sizeof(char) * strlen(temp.name) + 1);
		people[i].job = (char *)malloc(sizeof(char) * strlen(temp.job) + 1);
		strncpy_s(people[i].name, sizeof(temp.name) + 1, temp.name, sizeof(temp.name) + 1);
		strncpy_s(people[i].job, sizeof(temp.job) + 1, temp.job, sizeof(temp.job) + 1);
	}
	
}

void ReadJobInfo(Jobinfo people[], int count)
{
	int i;

	for (i = 0; i < count; i++)
	{
		printf("%s, %s\n", people[i].name,people[i].job);
	}
}
int main(void)
{
	Jobinfo * job;
	int count;

	printf("How many input to job of peaple? : "); scanf_s("%d", &count);
	job = (Jobinfo *)malloc(sizeof(Jobinfo) * count);
	InputJobInfo(job, count);
	ReadJobInfo(job, count);

	return 0;
}
