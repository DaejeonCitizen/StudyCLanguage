#ifndef __REMOVEBSN_H__
#define __REMOVEBSN_H__

void RemoveBSN(char str[])
{
	str[strlen(str) - 1] = 0;
}

#endif