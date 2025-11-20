#include "main.h"

char buffer[1024];
int buff_index = 0;

int add_to_buffer(char c)
{
	if (buff_index >= 1024)
	{
		write(1, buffer, buff_index);
		buff_index = 0;
	}
	buffer[buff_index++] = c;
	return (1);
}

void flush_buffer(void)
{
	if (buff_index > 0)
	{
		write(1, buffer, buff_index);
		buff_index = 0;
	}
}

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
	int match;
	dir dir[] = { {"c", count_char}, {"s", count_string},
		{"%", count_percent}, {"d", count_int},
		{"i", count_int}, {"b", conv_int}, 
		{"u", conv_baset}, {"o", conv_oct}, {"x", conv_lowhec},
		{"X", conv_upphec}, {"S", count_nonprint}, 
		{"p", count_pointer}, {NULL, NULL}
	};

	total = 0;
	count = 0;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format[count] != '\0')
	{
		if (format[count] == '%')
		{
			if (format[count + 1] == '\0')
			{
				va_end(args);
				return (-1);
			}
			match = 0;
			for (count_dir = 0; dir[count_dir].symbol != NULL; count_dir++)
			{
				if (format[count + 1] == dir[count_dir].symbol[0])
				{
					total += dir[count_dir].print(args);
					match = 1;
					break;
				}
			}
			if (!match)
			{
				add_to_buffer(format[count]);
				add_to_buffer(format[count + 1]);
				total += 2;
			}
			count += 2;
		}
		else
		{
			add_to_buffer(format[count]);
			total++;
			count++;
		}
	}
	va_end(args);
	flush_buffer();
	return (total);
}
