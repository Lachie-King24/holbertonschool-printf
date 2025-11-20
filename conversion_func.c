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
	char tmp;

	count = 0;

	if (num == 0)
	{
		tmp = '0';
		write(1, &tmp, 1);
		return (1);
	}

	while (num > 0)
	{
		digits[count] = num % 10;
		num /= 10;
		count++;
	}

	for (loopCount = count - 1; loopCount >= 0; loopCount--)
	{
		tmp = digits[loopCount] + '0';
		write(1, &tmp, 1);
	}
	return (count);
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
        char tmp;

        count = 0;

        if (num == 0)
        {
                tmp = '0';
                write(1, &tmp, 1);
                return (1);
        }

        while (num > 0)
        {
                digits[count] = num % 8;
                num /= 8;
                count++;
        }

        for (loopCount = count - 1; loopCount >= 0; loopCount--)
        {
                tmp = digits[loopCount] + '0';
                write(1, &tmp, 1);
        }
        return (count);
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
        char tmp;

        count = 0;

        if (num == 0)
        {
                tmp = '0';
                write(1, &tmp, 1);
                return (1);
        }

        while (num > 0)
        {
                digits[count] = num % 16;
                num /= 16;
                count++;
        }

        for (loopCount = count - 1; loopCount >= 0; loopCount--)
        {
		if (digits[loopCount] < 10)
		{
			tmp = digits[loopCount] + '0';
		}
		else
		{
			tmp = digits[loopCount] - 10 + 97;
		}
                write(1, &tmp, 1);
        }
        return (count);
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
        char tmp;

        count = 0;

        if (num == 0)
        {
                tmp = '0';
                write(1, &tmp, 1);
                return (1);
        }

        while (num > 0)
        {
                digits[count] = num % 16;
                num /= 16;
                count++;
        }

        for (loopCount = count - 1; loopCount >= 0; loopCount--)
        {
                if (digits[loopCount] < 10)
                {
                        tmp = digits[loopCount] + '0';
                }
                else
                {
                        tmp = digits[loopCount] - 10 + 65;
                }
                write(1, &tmp, 1);
        }
        return (count);
}
