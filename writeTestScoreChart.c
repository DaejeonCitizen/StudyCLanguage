#include <stdio.h>

int main(void)
{
	int i, j;
	int arr[5][5] = { 0, };
	char * SUB[4] = { "Korean","English","Math","History" };
	char * STUD[4] = { "Adel","Beyonce","Chainsmoker","D.angelo" };

	for (i = 0; i < 4; i++) //input score
		for (j = 0; j < 4; j++)
		{
			printf("input %s score of %s : ", SUB[j], STUD[i]);
			scanf("%d", &arr[i][j]);
		}

	for (i = 0; i < 4; i++) //output score + total
	{
		for (j = 0; j < 4; j++)
		{
			printf("%-3d", arr[i][j]);
			arr[i][4] += arr[i][j]; //total score of student
			arr[4][j] += arr[i][j]; //total score of subject
			if (j == 3)
			{
				printf("%-3d\n", arr[i][4]); //output total score of student
				arr[4][4] += arr[i][4]; //total score of all
			}
		}
		if (i == 3)
			for (j = 0; j < 5; j++) //output total score of subject
				printf("%-3d", arr[4][j]);
	}

	return 0;
}
