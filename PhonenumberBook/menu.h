#include "phonenuminfo.h"
#ifndef __MENU_H__
#define __MENU_H__

extern Pnuminfo * InsertPn(Pnuminfo pbook[], int * recnt);
extern Pnuminfo * DeletePn(Pnuminfo pbook[], int * recnt);
extern void SearchPn(Pnuminfo pbook[], int * recnt);
extern void PrintAllPn(Pnuminfo pbook[], int * recnt);
extern Pnuminfo * SavePn(Pnuminfo pbook[], int * recnt);
extern Pnuminfo * LoadPn(Pnuminfo pbook[], int * recnt);

#endif