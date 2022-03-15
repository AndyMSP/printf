#include "main.h"


/**
 * _pow - finds base to the power of exp
 * @base: int base
 * @exp: int exponent
 *
 * Return: integer result
 */
int _pow(int base, int exp)
{
	int result = 1;

	while (exp != 0)
	{
		result *= base;
		exp--;
	}

	return (result);
}

/**
 * char2str - converts a char to a pointer to char and int
 * @ap: ap_list previously generated
 *
 * Return: struct containing a string and its length
 */
printable char2str(va_list ap)
{
	char ch;
	char *str_char;
	printable result;

	ch = va_arg(ap, int);

	str_char = malloc(sizeof(char));
	str_char[0] = ch;

	result.str = str_char;
	result.len = 1;

	return (result);
}


/**
 * str2str - converts a string into a pointer to a char and int
 * @ap: ap_list previously generated
 *
 * Return: structure containing a string and its length
 */
printable str2str(va_list ap)
{
	char *str_char;
	int len;
	printable result;

	str_char = va_arg(ap, char *);

	/*find length of string without null byte*/
	len = 0;
	while (str_char[len] != '\0')
	{
		len++;
	}

	result.str = malloc(len * sizeof(char));
	result.str = str_char;
	result.len = len;

	return (result);
}

/**
 * mod2str - converts a mod into a pointer to a char and int
 * @ap: ap_list previously generated
 *
 * Return: structure containing a string and its length
 */

printable mod2str(va_list ap)
{
	printable result;

	(void)ap;

	result.str = malloc(sizeof(char));
	result.str[0] = '%';
	result.len = 1;

	return (result);
}


/**
 * int2str - converts an integer into a string and int
 * @ap: ap_list previously generated
 *
 * Return: structure containing a string and its length
 */

printable int2str(va_list ap)
{
	int num, i, len, *str_int, neg;
	int buf;
	char *str_char;
	printable result;

	num = va_arg(ap, int);

	(void)neg;

	if (num < 0)
	{
		neg = 1;
		num = num * -1;
	}

	/*find number of digits len*/
	buf = num;
	i = 0;
	while (buf != 0)
	{
		buf /= 10;
		i++;
	}
	len = i;

	/*allocate space for new storage arrays*/
	str_int = malloc(sizeof(int) * len);
	str_char = malloc(sizeof(char) * len);

	/*extract digits and store in str_int array*/
	buf = num;
	for (i = 0; i < len; i++)
	{
		str_int[i] = buf / _pow(10, (len - i - 1));
		buf = buf % _pow(10, (len - i - 1));
	}

	/*convert int array to char array*/
	for (i = 0; i < len; i++)
	{
		str_char[i] = '0' + str_int[i];
	}

	result.str = str_char;
	result.len = len;

	return (result);
}


/**
 * mis2str converts %* into a string and an int
 * @ap: va_list previously generated
 *
 * Return: structure containing a string and its length
 */

