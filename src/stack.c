#include <stdio.h>
#include "../include/calc.h"

#define MAX_VAL 100

static double val[MAX_VAL]; /* stack of storing value */
static int sp = 0; /* top position of stack  */

void push(double f)
{
	if (sp < MAX_VAL)
	{
		val[sp++] = f;
	}
	else
	{
		printf("ERROE: stack full, can't push %g\n", f);
	}
}

double pop(void)
{
	if (sp > 0)
	{
		return val[--sp];
	}
	else
	{
		printf("ERROR: stack empty\n");
		return 0.0;
	}
}

void clear(void)
{
	sp = 0; // clear the stack
} 