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
	printable (*f)(va_list, char);

} con_type;

int _printf(const char *format, ...);
long int _pow(long int base, long int exp);
printable char2str(va_list, char);
printable int2str(va_list, char);
printable str2str(va_list, char);
printable mod2str(va_list, char);
printable mis2str(va_list, char);

#endif
