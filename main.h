#ifndef _PRINTF_
#define _PRINTF_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "_putchar.c"
#include "probando.c"

typedef struct caract
{
	char sim;
	int (*f)(va_list);
}type_ch;

int _printf(const char *format, ...);

int _putchar(char c);

int c_formatic(va_list c);

int s_formatic(va_list s);

int d_formatic(va_list d);

int i_formatic(va_list d);

int porcent_formatic(va_list porcent);




#endif

