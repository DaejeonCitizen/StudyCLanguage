#include <stdio.h>
#include "ArrayList.h"

int main(void)
{
	/*** Creation and initialize of arrayList ***/
	List list;
	LData data;
	int sum = 0;
	int i;
	ListInit(&list);

	/*** Insert of 1~9 data ***/
	for (i = 0; i < 9; i++)
	{
		LInsert(&list, i + 1);
	}

	/*** Print all of saved data ***/
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if(LFirst(&list, &data))    // Check first data
	{
		sum += data;
		
		while (LNext(&list, &data))    // Check to second data after this
			sum += data;

		printf("Sum of all data : %d", sum);
		sum = 0;
	}
	printf("\n\n");

	/*** Search 22 and delete ***/
	if(LFirst(&list, &data))
	{
		if((data % 2) == 0 || (data % 3) == 0)
			LRemove(&list);
		
		while(LNext(&list, &data))
		{
			if((data % 2) == 0 || (data % 3) == 0)
				LRemove(&list);
		}
	}

	/*** Print all data after delete ***/
	printf("Num of data: %d \n", LCount(&list));

	if(LFirst(&list, &data))
	{
		printf("%d ", data);
		
		while(LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");
	return 0;
}