#include "main.h"

/**
 * count_char - Prints a single character to stdout
 * @args: Va_list containing character to stdout
 *
 * Return: 1
 */
int count_char(va_list args)
{
	char c = va_arg(args, int);

	write(1, &c, 1);
	return (1);
}

/**
 * count_string - prints and counts full string to stdout.
 * @args: va_list containing string to stdout.
 * Return: length of string.
 */
int count_string(va_list args)
{
	char *s = va_arg(args, char *);
	int length;

	length = 0;

	if (s == NULL)
		return (0);

	while (s[length] != '\0')
	{
		length++;
	}
	write(1, s, length);

	return (length);
}

/**
 * count_percent - prints a % sign as a char and writes to stdout.
 * @args: va_list unused.
 * Return: 1.
 */
int count_percent(va_list args)
{
	char percent = '%';

	(void) args;
	write(1, &percent, 1);
	return (1);
}
