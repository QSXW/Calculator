#include <stdio.h>
#include "../include/calc.h"

#define BUF_SIZE 100

static char buf[BUF_SIZE]; /* buffer for ungetch */
static int bufp = 0; /* nex free position of buf */

int getch(void)
{
	if (bufp > 0)
	{
		return buf[--bufp];
	}
	else
	{
		return getchar();
	}
}

void ungetch(int c)
{
	if (bufp > BUF_SIZE)
	{
		printf("ungetch: too many characters\n");
	}
	else
	{
	buf[bufp++] = c;
	}
}