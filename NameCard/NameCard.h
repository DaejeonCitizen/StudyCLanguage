#ifndef __NAMECARD_H__
#define __NAMECARD_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NAME_LEN 30
#define PHONE_LEN 30

typedef struct __namecard
{
	char name[NAME_LEN];
	char phone[PHONE_LEN];
} NameCard;

// return address after reset and malloc of struct variable
NameCard * MakeName(char * name, char * phone);

// print information of struct variable
void ShowNameCardInfo(NameCard * pcard);

// return if same name 0 else non 0 value
int NameCompare(NameCard * pcard, char * name);

// change phone information
void ChangePhoneNum(NameCard * pcard, char * name);

#endif