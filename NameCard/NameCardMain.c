#include "ArrayList.h"
#include "NameCard.h"

int main(void)
{
	List list;
	char * name = "Mom";
	char * phone = "010-0000-0000";
	LData namecard;
	

	ListInit(&list);

	namecard = MakeName("Kim", "010-4081-7889");
	LInsert(&list, namecard);
	namecard = MakeName("Mom", "010-5895-8789");
	LInsert(&list, namecard);
	namecard = MakeName("Guchung", "042-611-6705");
	LInsert(&list, namecard);

	puts("**Show All NameCard**");
	if (LFirst(&list, &namecard))
	{
		ShowNameCardInfo(namecard);
		while (LNext(&list, &namecard))
			ShowNameCardInfo(namecard);
	}

	puts("\n**Change Mom Phone**\n");
	if (LFirst(&list, &namecard))
	{
		if (!NameCompare(namecard, "Mom"))
		{
			ShowNameCardInfo(namecard);
			ChangePhoneNum(namecard, "010-0000-0000");
		}

		while (LNext(&list, &namecard))
			if (!NameCompare(namecard, "Mom"))
			{
				ShowNameCardInfo(namecard);
				ChangePhoneNum(namecard, "010-0000-0000");
			}
	}

	puts("\n**Delete Kim NameCard**\n");
	if (LFirst(&list, &namecard))
	{
		if (!NameCompare(namecard, "Kim"))
		{
			namecard = LRemove(&list);
			free(namecard);
		}

		while (LNext(&list, &namecard))
		{
			if (!NameCompare(namecard, "Kim"))
			{
				namecard = LRemove(&list);
				free(namecard);
			}
		}
	}
	
	puts("**Show All NameCard**");
	if (LFirst(&list, &namecard))
	{
		ShowNameCardInfo(namecard);
		while (LNext(&list, &namecard))
			ShowNameCardInfo(namecard);
	}

	while (LFirst(&list, &namecard))
	{
		namecard = LRemove(&list);
		free(namecard);
	}

	return 0;
}