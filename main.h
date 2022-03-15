#ifndef PRINTF_H
#define PRINTF_H

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

typedef struct str_and_len
{
	char *str;
	int len;

} printable;

typedef struct conversions
{
	char spec;
	printable (*f)(va_list);

} con_type;

int _printf(const char *format, ...);
int _pow(int base, int exp);
printable char2str(va_list ap);
printable int2str(va_list ap);
printable str2str(va_list ap);
printable mod2str(va_list ap);
printable mis2str(va_list ap);

#endif
