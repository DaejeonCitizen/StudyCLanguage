#include <stdio.h>
#include "ArrayList.h"

void ListInit(List * plist)
{
	int i;
	
	for (i = 0; i < LIST_LEN; i++)
		plist->arr[i] = 0;

	plist->numOfData = 0;
	plist->curPosition = 0;
}

void LInsert(List * plist, LData data)
{
	plist->arr[plist->numOfData] = data;

	(plist->numOfData)++;
	(plist->curPosition)++;
}

int LFirst(List * plist, LData * data)
{
	plist->curPosition = 0;

	if (plist->numOfData != 0)
	{
		*data = plist->arr[plist->curPosition];
		(plist->curPosition)++;
		return TRUE;
	}
	else
		return FALSE;
}

int LNext(List * plist, LData * data)
{
	if (plist->curPosition < plist->numOfData)
	{
		*data = plist->arr[plist->curPosition];
		(plist->curPosition)++;
		return TRUE;
	}
	else
		return FALSE;
}

LData LRemove(List * plist)
{
	static int check = -1;
	int i;
	LData temp = plist->arr[(plist->curPosition) - 1];
	
	if ((plist->curPosition) == check - 1)
		return;
	check = plist->curPosition;

	plist->arr[(plist->curPosition) - 1] = 0;

	for (i = (plist->curPosition); !((plist->arr[i - 1] == 0) && (plist->arr[i] == 0)); i++)
	{
		plist->arr[i - 1] = plist->arr[i];
	}

	(plist->numOfData)--;
	if (plist->curPosition > 0)
		(plist->curPosition)--;
}

int LCount(List * plist)
{
	return plist->numOfData;
}