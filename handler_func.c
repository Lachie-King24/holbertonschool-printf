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

	return (add_to_buffer(c));
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
		s = "(null)";

	while (*s)
	{
		add_to_buffer(*s++);
		length++;
	}
	return (length);
}

/**
 * count_percent - prints a % sign as a char and writes to stdout.
 * @args: va_list unused.
 * Return: 1.
 */
int count_percent(va_list args)
{
	(void) args;
	return (add_to_buffer('%'));
}

/**
 * count_int - prints an int to stdout
 * @args: va_list containing int
 * Return: int
 */

int count_int(va_list args)
{
int num = va_arg(args, int);
unsigned int n;
char buffer[12];
int i;
int length;

i = 0;
length = 0;

if (num < 0)
{
	add_to_buffer('-');
	length++;
	n = -num;
}
else
	n = num;

if (num == 0)
{
	return (add_to_buffer('0'));
}
while (n > 0)
{
	buffer[i++] = (n % 10) + '0';
	n /= 10;
}
while (i-- > 0)
{
	add_to_buffer(buffer[i]);
	length++;
}
return (length);
}

int count_nonprint(va_list args)
{
	char *s = va_arg(args, char *);
	int length;
	int count;
	char c;
	char hex[3];
	unsigned char uc;

	length = 0;

	if (!s)
		s = "(null)";

	for (count = 0; s[count] != '\0'; count++)
	{
		c = s[count];
		if ((c > 0 && c < 32) || (c >= 127))
		{
			add_to_buffer('\\');
			add_to_buffer('x');

			uc = (unsigned char)c;
			hex[0] = "0123456789ABCDEF"[uc / 16];
			hex[1] = "0123456789ABCDEF"[uc % 16];

			add_to_buffer(hex[0]);
			add_to_buffer(hex[1]);

			length += 4;	
		}
		else
		{
			add_to_buffer(c);
			length++;
		}
	}
	return (length);
}
