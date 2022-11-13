#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
/**
 *
 *
 */
int (*get_funct(char formatic))(va_list)
{
	type_ch str[] = {
		{'c', c_formatic},
		{'s', s_formatic},
	/**	{'d', d_formatic},
		{'i', i_formatic},*/
		{'%', porcent_formatic},
		{'\0', NULL},
	};

	int a;

	for (a = 0; str[a].sim; a++)
	{
		if (formatic == str[a].sim)
		{
			return (str[a].f);
		}
	}
	return (NULL);
}
/**
 *
 *
 */
int _printf(const char *format, ...)
{
	int i, numChar = 0;
	va_list arg;
	int (*f)(va_list);

	if (format == NULL)
	{
		return (-1);
	}
	va_start(arg, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		for (; format[i] != '%' && format[i] != '\0'; i++)
		{
			if (format[i] != '\0')
			{
				_putchar(format[i]), numChar++;
			}
		}
		if (format[i] == '\0')
		{
			return (numChar);
		}
		f = *get_funct(format[i + 1]);
		if (f != NULL)
		{
			numChar += f(arg);
			continue;
		}
		if (format[i] == '\0')
		{
			return (-1);
		}
		_putchar(format[i]), numChar++;
		if (format[i + 1] == '%')
		{
			i += 2;
		}
	}
	va_end(arg);
	return (numChar);
}
