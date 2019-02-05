#pragma once

#define NUMBER '0'
#define NAME 'n'

void push(double f);
double pop(void);

int GetOp(char *s);

int getch(void);
void ungetch(int c);