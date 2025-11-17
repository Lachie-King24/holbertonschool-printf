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

	if (format == NULL)
	return (0);
	
	else
	{
		va_start(args, format);

		while (format[count] != '\0')
		{
			if (format[count] == '%')
			{
				if (format[count + 1] == '\0')
        				break;
				for (count_dir = 0; dir[count_dir].symbol != NULL; count_dir++)
				{
					if (format[count + 1] == dir[count_dir].symbol[0])
					{
						total += dir[count_dir].print(args);
						break;
					}
				}
				count += 2;
			}
			else
			{
				write(1, &format[count], 1);
				total++;
				count++;
			}
		}
		va_end(args);
		return (total);
	}
}
