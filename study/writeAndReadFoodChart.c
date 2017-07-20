#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char * name;
	char * maker;
	int price;
} Foodinfo;

typedef struct
{
	char name[20];
	char maker[20];
	int price;
} Foodinfotemp;

void GetFoodInfo(Foodinfo * info)
{
	char nametemp[20];
	char makertemp[20];
	static int count = 1;

	printf("%d. food info : ", count);
	scanf_s("%s %s %d", nametemp, sizeof(nametemp), makertemp, sizeof(makertemp), &info->price);
	getchar();

	info->name = (char *)malloc(strlen(nametemp) + 1);
	if (info->name == NULL) {
		puts("failed assign heap memory");
		return;
	}
	strncpy_s(info->name, strlen(nametemp) + 1, nametemp, strlen(nametemp) + 1);

	info->maker = (char *)malloc(strlen(makertemp) + 1);
	if (info->maker == NULL) {
		puts("failed assign heap memory");
		return;
	}
	strncpy_s(info->maker, strlen(makertemp) + 1, makertemp, strlen(makertemp) + 1);

	count++;
}

void OutputFoodChart(Foodinfo * info, int fdn)
{
	int i;
	FILE * fp = fopen("food_chart.bin", "wb");
	if (fp == NULL) {
		puts("failed open file");
	}
	for (i = 0; i < fdn; i++)
		fwrite((void*)&info[i], sizeof(info[i]), 1, fp);

	puts("SAVE COMPLETE");
	fclose(fp);
}

/*
void OutputFoodChart(Foodinfo * info)
{
	FILE * fp = fopen("food_chart.bin", "ab");
	if (fp == NULL) {
		puts("failed open file");
	}
	fwrite((void *)&info, sizeof(info), 1, fp);

	puts("SAVE COMPLETE");
	fclose(fp);
}
*/
void ReadFoodChart(void)
{
	int i = 0;
	Foodinfo * food;
	Foodinfotemp foodtemp;
	FILE * fp = fopen("food_chart.bin", "rb");
	if (fp == NULL) {
		puts("failed file open");
		return;
	}

	food = (Foodinfo*)malloc(sizeof(Foodinfo) * 1);

	while (1)
	{
		fread((void*)&foodtemp, sizeof(food[i]), 1, fp);

		food[i].name = (char *)malloc(strlen(foodtemp.name) + 1);
		strncpy_s(food[i].name, sizeof(food[i].name) + 1, foodtemp.name, sizeof(food[i].name) + 1);
		food[i].maker = (char *)malloc(strlen(foodtemp.maker) + 1);
		strncpy_s(food[i].maker, sizeof(food[i].maker) + 1, foodtemp.maker, sizeof(food[i].maker) + 1);
		food[i].price = foodtemp.price;

		if (!feof(fp))
		{
			food = (Foodinfo *)realloc(food, sizeof(Foodinfo)*(i + 2));
			i++;
		}
		else
			break;
	}

	for (; i >= 0; i--)
		printf("%s %s %d\n", food[i].name, food[i].maker, food[i].price);
	
}
int main(void)
{
	int fdn;
	int i;
	char choice[6];
	Foodinfo * food;
	
	printf("read or write? : "), scanf_s("%s", choice, sizeof(choice));
	if (!strncmp(choice, "read", sizeof(choice)))
		ReadFoodChart();

	printf("How many get food info? : ");
	scanf_s("%d",&fdn);
	food = (Foodinfo *)malloc(sizeof(Foodinfo)*fdn);
	if (food == NULL) {
		puts("failed assign heap memory");
		return -1;
	}
	
	printf("Please enter food name and maker and price.\n");

	for (i = 0; i < fdn; i++)
	{
		GetFoodInfo(&food[i]);
	}
	puts("------------------------------------");
	for (i = 0; i < fdn; i++)
	{
		printf("%d. food name : %s\n", i + 1, food[i].name);
		printf("%d. food maker : %s\n", i + 1, food[i].maker);
		printf("%d. food price : %d\n", i + 1, food[i].price);
		puts("------------------------------------");
	}

	printf("save or exit : "), scanf_s("%s", choice, sizeof(choice));
	if (!strncmp(choice, "save", sizeof(choice)))
		OutputFoodChart(food,fdn);
		
	for (i = 0; i < fdn; i++)
	{
		free(food[i].name);
		free(food[i].maker);
	}

	free(food);

	return 0;
}
