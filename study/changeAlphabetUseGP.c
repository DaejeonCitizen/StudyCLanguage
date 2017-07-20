#include <stdio.h>

int Chainge(int alp)
{
	return alp < 91 ? (alp += 32) : (alp -= 32);
}

int main(void)
{
	int ch = 0;

	ch = getchar();
	if ((ch > 64 && ch < 91) || (ch > 96 && ch < 123))
		putchar(Chainge(ch));
	else
		printf("ERROR : It's not alphabet");

	return 0;
}
