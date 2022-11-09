#ifndef PRINTF_HEADER
#define PRINTF_HEADER
#include <stdio.h>
#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>

int _strlen(char *s);
int print(long int n);
int _prontf(const char *format, va_list args);
int _printf(const char *format, ...);
int FromDeci(unsigned long int n, int base);
int lowercaseDeciFunc(long int n, int base);
void unsigned_ntostring(unsigned long int number, int base, char *buffer);
void ntotring(long long int number, int base, char *buffer);
void uppercase_ntostring(unsigned long int number, int base, char *buffer);

/*****************************************************************************/
/**
 * unsigned_ntostring - Transforms a number into a string.
 * @number: Number to be transformed, positive due to ntostrings transofmration
 * @base: Transforms to (base 10) from base.
 * @buffer: Holds data temporarily
 */

void unsigned_ntostring(unsigned long int number, int base, char *buffer)
{
	int digit;
	int cur = 0;
	int i;
	char buf[65];

	if (number == 0)
	{
		*buffer++ = '0';
		*buffer = 0;
	}
	for (i = 0; i < 65; i++)
		buf[i] = 0;
	while (number)
	{
		digit = number % base;
		if (digit >= 10)
			buf[cur++] = 'a' + (digit - 10);
		else
			buf[cur++] = '0' + digit;
		number /= base;
	}
	for (i = cur - 1; i != 0; i--)
		*buffer++ = buf[i];
	*buffer++ = buf[0];
	*buffer = 0;
}

/*****************************************************************************/
/**
 * ntostring - Calls upon unsignedntostring to turn a number into a string.
 * @number: Number to be transformed, negative or positive.
 * @base: Also transforms to base from base ten.
 * @buffer: Holds the data temporarily.
 */

void ntostring(long long int number, int base, char *buffer)
{
	if (number < 0)
	{
		*buffer++ = '-';
		number = -number;
	}
	unsigned_ntostring(number, base, buffer);
}

/*****************************************************************************/
/**
 * uppercase_ntostring - Like unsigned ntostring but returns uppercase chars.
 * @number: Number to be transformed, only positives.
 * @base: Transforms from base ten to base base
 * @buffer: Holds the data momentarily.
 */

void uppercase_ntostring(unsigned long int number, int base, char *buffer)
{
	int digit;
	int cur = 0;
	int i;
	char buf[65];
	if (number == 0)
	{
		*buffer++ = '0';
		*buffer = 0;
	}
	for (i = 0; i < 65; i++)
		buf[i] = 0;
	while (number)
	{
		digit = number % base;
		if (digit >= 10)
			buf[cur++] = 'A' + (digit - 10);
		else
			buf[cur++] = '0' + digit;
		number /= base;
	}
	for (i = cur - 1; i != 0; i--)
		*buffer++ = buf[i];
	*buffer++ = buf[0];
	*buffer = 0;
}

/*****************************************************************************/
/**
 * lowercaseDeciFunc - Prints a number from base ten to base but in lowercase.
 * @n: Number to be transformed and printed.
 * @base: Base to transfrom number into.
 * Return: Returns amount of characters printed.
 */

int lowercaseDeciFunc(long n, int base)
{
	long decimalnum, quotient, remainder;
	int i, j = 0;
	int strlen = 0;
	char hexadecimalnum[100];
	decimalnum = n;
	quotient = decimalnum;
	while (quotient != 0)
	{
		remainder = quotient % base;
		if (remainder < 10)
			hexadecimalnum[j++] = 48 + remainder;
		else
			hexadecimalnum[j++] = 55 + remainder;
		quotient = quotient / base;
	}
	for (i = j; i >= 0; i--)
		if (hexadecimalnum[i] > 'A' && hexadecimalnum[i] < 'Z')
		{
			putchar(hexadecimalnum[i] + 32);
			strlen++;
		}
		else
		{
			putchar(hexadecimalnum[i]);
			strlen++;
		}
	return (strlen);
}

/*****************************************************************************/
/**
 * FromDeci - Scrapped due to instability and bad output.
 * @n: Number to be printed.
 * @base: Base to be transform number into.
 * Return: Returns the amount of characters printed.
 */

int FromDeci(unsigned long n, int base)
{
	unsigned long decimalnum, quotient, remainder;
	int i, j = 0;
	char hexadecimalnum[100];
	int strlen = 0;

	decimalnum = n;
	quotient = decimalnum;
	while (quotient != 0)
	{
		remainder = quotient % base;
		if (remainder <= 10)
			hexadecimalnum[j++] = 48 + remainder;
		else
			hexadecimalnum[j++] = 55 + remainder;
		quotient = quotient / base;
	}
	for (i = j; i >= 0; i--)
	{
		putchar(hexadecimalnum[i]);
		strlen++;
	}
	return (strlen);
}

/*****************************************************************************/
/**
 * _strlen - Function that measures the lenght of a string.
 * @s: String to be measured.
 * Return: Returns the lenght of the string to the function.
 */

int _strlen(char *s)
{
	int i;
		for (i = 0; s[i]; i++)
		;
	return (i);
}
/****************************************************************************/
/**
 * print - prints a number using recursion, scraped for better functions.
 * @n: Number to be printed.
 * Return: No return.
 */
int print(long int n)
{
	if (n < 0)
	{
		putchar('-');
		n = -n;
	}
	if (n / 10)
		print(n / 10);
	putchar(n % 10 + '0');
}

#endif
