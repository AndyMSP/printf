#include "main.h"



/**
 * get_op - chooses function to use on next parameter
 *
 * Return: pointer to function that returns struct of type printable
 */
printable(*get_op(char ch))(va_list)
{
	unsigned int i = 0;
	con_type picker[] = {
		{'c', char2str},
		{'s', str2str},
		{'d', int2str},
		{'i', int2str},
		{'%', mod2str},
	};

	while (i < sizeof(picker) / sizeof(picker[0]))
	{
		if (ch == picker[i].spec)
			return (picker[i].f);
		i++;
	}

	return (0);
}



/**
 * _printf - prints formatted text to standard output
 * @format: pointer to char giving format instructions
 *
 * Return: int number of characters printed not including null byte
 */

int _printf(const char *format, ...)
{
	int i, len = 0;
	va_list ap;
	printable buffer;
	printable (*convert)(va_list);

	va_start(ap, format);

	i = 0;
	while (format[i] != 0)
	{
		if (format[i] == '%')
		{
			i++;
			convert = get_op(format[i]);
			buffer = convert(ap);
			write(1, buffer.str, buffer.len);
			len += buffer.len;
			free(buffer.str);
		}
		else
		{
			write(1, &format[i], 1);
			len++;
		}
	i++;
	}

	va_end(ap);

	return (len);
}
