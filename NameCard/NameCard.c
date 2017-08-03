#include "NameCard.h"

NameCard * MakeName(char * name, char * phone)
{
	NameCard * pnmcd = (NameCard *)malloc(sizeof(NameCard));
	
	strcpy_s(pnmcd->name, strlen(name) + 1, name);
	strcpy_s(pnmcd->phone, strlen(phone) + 1, phone);

	return pnmcd;
}

void ShowNameCardInfo(NameCard * pcard)
{
	printf("Name : %-15sPhone : %-15s\n", pcard->name, pcard->phone);
}

int NameCompare(NameCard * pcard, char * name)
{
	return strcmp(pcard->name, name);
}

void ChangePhoneNum(NameCard * pcard, char * phone)
{
	strcpy_s(pcard->phone, strlen(phone) + 1, phone);
}