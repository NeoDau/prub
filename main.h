#ifndef _PRINTF_
#define _PRINTF_

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct caract
{
	char sim;
	int (*f)(va_list);
} type_ch;

int _printf(const char *format, ...);

int (*get_funct(char formatic))(va_list);

int _putchar(char c);

int c_formatic(va_list arg);

int s_formatic(va_list arg);

int d_formatic(va_list arg);

int i_formatic(va_list arg);

/**int porcent_formatic(va_list arg);*/


#endif

