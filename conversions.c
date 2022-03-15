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
printable char2str(va_list ap, char garb)
{
	char ch;
	char *str_char;
	printable result;

	(void)garb;

	ch = va_arg(ap, int);

	str_char = malloc(sizeof(char));
	if (str_char == NULL)
	{
		result.len = 0;
		result.str = NULL;
		return (result);
	}
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
printable str2str(va_list ap, char garb)
{
	char *str_char;
	int len, i;
	printable result;

	(void)garb;

	str_char = va_arg(ap, char *);

	/*find length of string without null byte*/
	len = 0;
	while (str_char[len] != '\0')
	{
		len++;
	}

	result.str = malloc(len * sizeof(char));
	if (result.str == NULL)
	{
		result.len = 0;
		result.str = NULL;
		return (result);
	}

	for (i = 0; i < len; i++)
		result.str[i] = str_char[i];

	result.len = len;

	return (result);
}

/**
 * mod2str - converts a mod into a pointer to a char and int
 * @ap: ap_list previously generated
 *
 * Return: structure containing a string and its length
 */

printable mod2str(va_list ap, char garb)
{
	printable result;

	(void)ap;
	(void)garb;

	result.str = malloc(sizeof(char));
	if (result.str == NULL)
	{
		result.len = 0;
		result.str = NULL;
		return (result);
	}

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

printable int2str(va_list ap, char garb)
{
	int i, j, len, *str_int, neg;
	long int num, buf;
	char *str_char;
	printable result;

	(void)garb;

	num = va_arg(ap, int);

	if (num < 0)
	{
		num = num * -10;
		neg = 1;
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
	str_int = malloc(sizeof(long int) * len);
	if (str_int == NULL)
	{
		result.len = 0;
		result.str = NULL;
		return (result);
	}
	str_char = malloc(sizeof(char) * len);
	if (str_char == NULL)
	{
		result.len = 0;
		result.str = NULL;
		return (result);
	}

	/*extract digits and store in str_int array*/
	buf = num;
	for (i = 0; i < len; i++)
	{
		str_int[i] = buf / _pow(10, (len - i - 1));
		buf = buf % _pow(10, (len - i - 1));
	}

	/*convert int array to char array*/
	if (neg == 1)
	{
		str_char[0] = '-';
		i = 1;
	}
	else
	{
		i = 0;
	}

	for (j = 0; i < len; j++)
	{
		str_char[i] = '0' + str_int[j];
		i++;
	}

	free(str_int);

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
printable mis2str(va_list ap, char garb)
{
	printable result;

	(void)ap;

	result.str = malloc(sizeof(char) * 2);
	result.str[0] = '%';
	result.str[1] = garb;
	result.len = 2;

	return (result);
}
