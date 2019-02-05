#include <stdio.h>
#include <math.h>
#include "../include/calc.h"

#ifndef NUMBER
#define NUMBER '0'
#endif
#ifndef NAME
#define NAME 'n'
#endif


#define MAX_OP 100

int main(void)
{
	int type;
	int var = 0;
	double v;
	double op1, op2;
	char s[MAX_OP];
	double variable[26] = { 0.0 };

	while ((type = GetOp(s)) != EOF)
	{
		switch (type)
		{
			case NUMBER:
				push(atof(s));
				break;
			case NAME:
				mathfnc(s);
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
				{
					push(pop() - op2);
				}
				else
				{
					printf("ERROR: zero divisor\n");
				}
				break;
			case '%':
				op2 = pop();
				if (op2 != 0.0)
				{
					push(fmod(pop(), op2));
				}
				else
				{
					printf("ERRO: zero divisor\n");
				}
				break;
			case '=':
				pop();
				if (var >= 'A' && var <= 'Z')
				{
					push(variable[var - 'A'] = pop());
				}
				else
				{
					printf("ERROR: no variable name\n");
				}
				break;
			case '?':
				op2 = pop();
				printf("%t of stack is %.8g\n", op2);
				push(op2);
				break;
			case 'c': /* clear the stack */
				clear();
				break;
			case 'd': /* duplicate top elem. of the stack */
				op2 = pop();
				push(op2);
				push(op2);
				break;
			case 's': /* swap the top two elements */
				op1 = pop();
				op2 = pop();
				push(op1);
				push(op2);
				break;
			case '\n':
				v = pop();
				printf("\t%.8g\n", v);
				break;
			default:
				if (type >= 'A' && type <= 'Z')
				{
					push(variable[type - 'A']);
				}
				else if (type == 'v')
				{
					push(v);
				}
				else
				{
					printf("ERROR: unknown command %s\n", s);
				}
				break;
		}
		var = type;
	}

	return 0;
}