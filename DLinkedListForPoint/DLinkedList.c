#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void ListInit(List * plist)
{
	plist->head = (Node *)malloc(sizeof(Node));
	plist->head->next = NULL;
	plist->numOfData = 0;
	plist->comp = NULL;
}

void FInsert(List * plist, LData data)
{
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	
	newNode->next = plist->head->next;
	plist->head->next = newNode;

	(plist->numOfData)++;
}

void SInsert(List * plist, LData data)
{
	// after later..
}

void LInsert(List * plist, LData data)
{
	if (plist->comp == NULL)
		FInsert(plist, data);
	else
		SInsert(plist, data);
}
int LFirst(List * plist, LData * pdata)
{
	if (plist->head->next == NULL)
		return FALSE;
	
	plist->before = plist->head;
	plist->cur = plist->head->next;

	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List * plist, LData * pdata)
{
	if (plist->cur->next == NULL)
		return FALSE;
	
	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

LData LRemove(List * plist)
{
	LData rdata = plist->cur->data;

	plist->before->next = plist->cur->next;
	free(plist->cur);
	plist->cur = plist->before;

	(plist->numOfData)--;
	return rdata;
}

int LCount(List * plist)
{
	return plist->numOfData;
}

void SetSortRule(List * plist, int(*comp)(LData d1, LData d2))
{
	// after later..
}