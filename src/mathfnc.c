#include <stdio.h>
#include "../include/calc.h"

#define SIN "sin"
#define COS "cos"
#define EXP "exp"
#define POW "pow"

void mathfnc(char *s)
{
	double op2 = 0.0;

	if (strcmp(s, SIN) == 0)
	{
		push(sin(pop()));
	}
	else if (strcmp(s, COS) == 0)
	{
		push(cos(pop()));
	}
	else if (strcmp(s, EXP) == 0)
	{
		push(exp(pop()));
	}
	else if (strcmp(s, POW) == 0)
	{
		op2 = pop();
		push(pow(pop(), op2));
	}
	else
	{
		printf("ERROR: command %s not supported\n", s);
	}
}