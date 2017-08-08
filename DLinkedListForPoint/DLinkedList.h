#ifndef __DLINKEDLIST_H__
#define __DLINKEDLIST_H__

#include "Point.h"

#define TRUE 1
#define FALSE 0

typedef Point * LData;

typedef struct _node
{
	LData data;
	struct _node * next;
} Node;

typedef struct _linkedlist
{
	Node * head;
	Node * cur;
	Node * before;
	int numOfData;
	int(*comp)(LData d1, LData d2);
} LinkedList;

typedef LinkedList List;

void ListInit(List * plist);
void LInsert(List * plist, LData data);

int LFirst(List * plist, LData * data);
int LNext(List * plist, LData * data);

LData LRemove(List * plist);
int LCount(List * plist);

void SetSortRule(List * plist, int(*comp)(LData d1, LData d2));

#endif