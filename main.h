#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - copies main function printf
 * @format: input to print
 * Return: count of result
 */

int _printf(const char *format, ...);
int count_char(va_list args);
int count_string(va_list args);
int count_percent(va_list args);
int count_int(va_list args);
int conv_int(va_list args);
int conv_baset(va_list args);
int conv_oct(va_list args);
int conv_lowhec(va_list args);
int conv_upphec(va_list args);
int add_to_buffer(char c);
void flush_buffer(void);
int count_nonprint(va_list args);

/**
 * struct directives - structure for % directives
 * @symbol: specifier (c, s, %)
 * @print: function pointer to the correct handler
 */

struct directives
{
	char *symbol;
	int (*print)(va_list);
};

typedef struct directives dir;

#endif
