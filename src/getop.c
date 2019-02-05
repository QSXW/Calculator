#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "../include/calc.h"

int GetOp(char *s)
{
	int i = 0;
	int c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
	{
		NULL; /* Skip the blank */
	}
	s[1] = '\0';
	if (isalpha(c))
	{
		while (isalpha(s[++i] = c = getch()))
		{
			NULL;
		}
		s[i] = '\0';
		if (c != EOF)
		{
			ungetch(c);
		}
		if (strlen(s) > 1)
		{
			return NAME;
		}
		else
		{
			return (s[0]);
		}
	}
	if (!isdigit(c) && c != '.' && c != '-')
	{
		return c;
	}
	if (c == '-')
	{
		if (isdigit(c = getch()) || c == '.')
		{
			s[++i] = c;
		}
		else
		{
			if (c != EOF)
			{
				ungetch(c);
				return '-';
			}
		}
	}
	if (isdigit(c))
	{
		while (isdigit(s[++i] = c = getch()))
		{
			NULL;
		}
	}
	if (c == '.')
	{
		while (isdigit(s[++i] = c = getch()))
		{
			NULL; // Skip the decimal points
		}
	}
	s[i] = '\0';
	if (c != EOF)
	{
		ungetch(c);
	}

	return NUMBER;
}