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
		s = "(null)";

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
	write(1, "-", 1);
	length++;
	n = -num;
}
else
	n = num;

if (num == 0)
{
	write(1, "0", 1);
	return (length + 1);
}
for (i = 0; n > 0; i++)
{
	buffer[i] = (n % 10) + '0';
	n /= 10;
}
for (i = i - 1; i >= 0; i--)
{
	write(1, &buffer[i], 1);
	length++;
}
return (length);
}

/**
 * conv_int - converts an unsigned int to binary
 * @args: va_list containing int
 * Return:
 */

int conv_int(va_list args)
{
int binaryNum[33];
int count;
int loopCount;
char tmp;
unsigned int num = va_arg(args, unsigned int);  

count = 0;

if (num == 0)
{
tmp = '0';
write(1, &tmp, 1);
return (1);
}

while (num > 0)
{
	binaryNum[count] = num % 2;
	num = num / 2;
	count++;
}

for (loopCount = count - 1; loopCount >= 0; loopCount--)
{
	tmp = binaryNum[loopCount] + '0';
	write(1, &tmp, 1);
}
return (count);
}
