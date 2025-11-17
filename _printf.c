#include "main.h"

/**
 * _printf - a duplicate function to the standard printf
 * @format: a character string, may or may not contain directives
 * Return: Number of characters printed, exc null byte
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count;
	int count_dir;
	int total;
	dir dir[] = {
		{"c", count_char},
		{"s", count_string},
		{"%", count_percent},
		{NULL, NULL}
	};

	total = 0;
	count = 0;

	va_start(args, format);

	while (format[count] != '\0')
	{
		count_dir = 0;
		while (dir[count_dir].symbol != NULL)
		{
			if (format[count] == '%')
			{
				if (format[count + 1] == dir[count_dir].symbol[0])
				{
					dir[count_dir].print(args);
					total += dir[count_dir].print(args);
				}
			}
			else
				total++
			count_dir++;
		}
		count++;
	}
	va_end(args);
	return (total);
}
