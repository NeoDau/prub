#include "main.h"
/**
 * _printf - Formatted printing function.
 * @format: String with possible format instructions.
 * Return: Returns the lenght of the printed output.
 */

int _printf(const char *format, ...)
{
        int strlen = 0;
        int escapeSequences = 0;
        int escapeSeqArray[] = {'d', 'i', 'c', 's', '%', 'u', 'x', 'X', 'p', 'o'};
        int arrayIterator;
        va_list args;
        int VaArg_len = 0;

        va_start(args, format);
        VaArg_len += _prontf(format, args);
        va_end(args);
        for (strlen = 0; format[strlen]; strlen++)
                if (format[strlen] == '%')
                {
                        for (arrayIterator = 0; escapeSeqArray[arrayIterator]; arrayIterator++)
                                if (format[strlen + 1] == escapeSeqArray[arrayIterator])
                                {
                                        escapeSequences++;
                                        strlen++;
                                        break;
                                }
                }
        printf("%d\n%d\n%d\n", VaArg_len, strlen, escapeSequences);
        return (strlen - (escapeSequences * 2) + VaArg_len);
}
/**
 * _prontf - Prints argument in the _printf function.
 * @format: Instruction on how to process argument.
 * @args: Argument to be printed instead of the format.
 * Return: Returns the lenght of the argument printed.
 */
int _prontf(const char *format, va_list args)
{
        int ctr = 0;
        int foundPercent = 0;
        int VaArg_len = 0;
        int iterate = 0;

        while (format[ctr])
        {
                if (!(foundPercent))
                {
                        if (format[ctr] == '%')
                        {
                                foundPercent = 1;
                        }
                        else
                        {
                                putchar(format[ctr]);
                        }
                }
                else if (foundPercent)
                {
                        switch (format[ctr])
                        {
                        case 's':
                        {
                        char *StringFormatReplacement = va_arg(args, char *);

                        VaArg_len += _strlen(StringFormatReplacement);
                        while (StringFormatReplacement[iterate])
                        {
                                putchar(StringFormatReplacement[iterate]);
                                iterate++;
                        }
                        break;
                        }
                        case 'c':
                        {
                        char CharFormatReplacement = va_arg(args, int);

                        putchar(CharFormatReplacement);
                        VaArg_len++;
                        break;
                        }
                        case '%':
                        {
                        VaArg_len++;
                        putchar('%');
                        break;
                        }
                        case 'd':
                        {
                        int DecimalFormatReplacement = va_arg(args, int);
                        char buf[32];
                        int i;

                        ntostring(DecimalFormatReplacement, 10, buf);
                        for (i = 0; buf[i]; i++)
                        {
                                VaArg_len++;
                                putchar(buf[i]);
                        }
                        break;
                        }
                        case 'i':
                        {
                        int IntegerFormatReplacement = va_arg(args, int);
                        char buf[32];
                        int i;

                        ntostring(IntegerFormatReplacement, 10, buf);
                        for (i = 0; buf[i]; i++)
                        {
                                VaArg_len++;
                                putchar(buf[i]);
                        }
                        break;
                        }
                        case 'u':
                        {
                        unsigned int UnsignedIntReplacement = va_arg(args, unsigned int);
                        char buf[32];
                        int i;

                        ntostring(UnsignedIntReplacement, 10, buf);
                        for (i = 0; buf[i]; i++)
                        {
                                putchar(buf[i]);
                                VaArg_len++;
                        }
                        break;
                        }
			case 'x':
                        {
                        long long HexFormatReplacement = va_arg(args, unsigned int);
                        char buf[25];
                        int i;

                        ntostring(HexFormatReplacement, 16, buf);
                        for (i = 0; buf[i]; i++)
                        {
                                putchar(buf[i]);
                                VaArg_len++;
                        }
                        break;
                        }
                        case 'X':
                        {
                        long long HexFormatBigboy = va_arg(args, unsigned int);
                        char buf[25];
                        int i;

                        uppercase_ntostring(HexFormatBigboy, 16, buf);
                        for (i = 0; buf[i]; i++)
                        {
                                putchar(buf[i]);
                                VaArg_len++;
                        }
                        break;
                        }
                        case 'o':
                        {
                        long OctalFormatReplacement = va_arg(args, unsigned int);
                        char buf[32];
                        int i;

                        ntostring(OctalFormatReplacement, 8, buf);
                        for (i = 0; buf[i]; i++)
                        {
                                putchar(buf[i]);
                                VaArg_len++;
                        }
                        break;
                        }
                        case 'p':
                        {
                        putchar('0');
                        putchar('x');
                        VaArg_len += 2;
                        void *PointerFormatReplacement = va_arg(args, void *);
                        char buf[32];
                        int i;

                        ntostring((unsigned long int)PointerFormatReplacement, 16, buf);
                        for (i = 0; buf[i]; i++)
                        {
                        VaArg_len++;
                        putchar(buf[i]);
                        }
                        break;
                        }
                        default:
                        {
                                putchar(format[ctr - 1]);
                                putchar(format[ctr]);
                                break;
                        }
                        }
                        foundPercent = 0;
                }
                ctr++;
        }
        return (VaArg_len);
}
