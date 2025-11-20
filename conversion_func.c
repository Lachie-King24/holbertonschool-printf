#include "main.h"

/**
 * conv_int - converts an unsigned int to binary
 * @args: va_list containing int
 * Return: count or zero
 */

int conv_int(va_list args)
{
int binaryNum[33];
int count;
int loopCount;
int length;
unsigned int num = va_arg(args, unsigned int);

count = 0;
length = 0;

if (num == 0)
	return (add_to_buffer('0'));

while (num > 0)
{
        binaryNum[count] = num % 2;
        num = num / 2;
        count++;
}

for (loopCount = count - 1; loopCount >= 0; loopCount--)
{
        add_to_buffer(binaryNum[loopCount] + '0');
        length++;
}
return (length);
}

/**
 * conv_baset - converts decimal to base10
 * @args: va_list containing int
 * Return:
 */

int conv_baset(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int digits[10];
	int count;
	int loopCount;
	int length;

	count = 0;
	length = 0;

	if (num == 0)
		return (add_to_buffer('0'));

	while (num > 0)
	{
		digits[count] = num % 10;
		num /= 10;
		count++;
	}

	for (loopCount = count - 1; loopCount >= 0; loopCount--)
	{
		add_to_buffer(digits[loopCount] + '0');
		length++;
	}
	return (length);
}

/**
 * conv_oct - converts decimal to octal
 * @args: va_list containing int
 * Return:
 */

int conv_oct(va_list args)
{
unsigned int num = va_arg(args, unsigned int);
        int digits[12];
        int count;
        int loopCount;
        int length;

        count = 0;
	length = 0;

        if (num == 0)
		return (add_to_buffer('0'));

        while (num > 0)
        {
                digits[count] = num % 8;
                num /= 8;
                count++;
        }

        for (loopCount = count - 1; loopCount >= 0; loopCount--)
        {
                add_to_buffer(digits[loopCount] + '0');
                length++;
        }
        return (length);
}

/**
 * conv_lowhec - converts decimal to hexadecimal in lowercase
 * @args: va_list containing int
 * Return:
 */

int conv_lowhec(va_list args)
{
unsigned int num = va_arg(args, unsigned int);
        int digits[10];
        int count;
        int loopCount;
	int length;
        char tmp;

        count = 0;
	length = 0;

	if (num == 0)
		return (add_to_buffer('0'));

        while (num > 0)
        {
                digits[count] = num % 16;
                num /= 16;
                count++;
        }

        for (loopCount = count - 1; loopCount >= 0; loopCount--)
        {
		if (digits[loopCount] < 10)
			tmp = digits[loopCount] + '0';
		else
			tmp = digits[loopCount] - 10 + 97;
                add_to_buffer(tmp);
		length++;
        }
        return (length);
}

/**
 * conv_uppconv - converts decimal to hexadecimal in uppercase
 * @args: va_list containing int
 * Return:
 */

int conv_upphec(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
        int digits[10];
        int count;
        int loopCount;
	int length;
        char tmp;

        count = 0;
	length = 0;

        if (num == 0)
		return (add_to_buffer('0'));

        while (num > 0)
        {
                digits[count] = num % 16;
                num /= 16;
                count++;
        }

        for (loopCount = count - 1; loopCount >= 0; loopCount--)
        {
		if (digits[loopCount] < 10)
			tmp = digits[loopCount] + '0';
		else
			tmp = digits[loopCount] - 10 + 65;
                add_to_buffer(tmp);
		length++;
        }
        return (length);
}
