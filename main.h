#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * Header file containing functions and structures
 */

int _printf(const char *format, ...);
int count_char(va_list args);
int count_string(va_list args);
int count_percent(va_list args);

struct directives 
{
	char *symbol;
	int (*print)(va_list);
};

typedef struct directives dir;

#endif
