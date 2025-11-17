#include "main.h"

/**
 * _printf - a duplicate function to the standard printf
 * @format: a character string, may or may not contain directives
 * Return: Number of characters printed, exc null byte
 */



/**
 * int _printf(const char *format, ...)
{
	va_list args;
	int count;
	int count_dir;
	int total;
	int match;
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
				match = 0;
				if (format[count + 1] == '\0')
        				break;
				for (count_dir = 0; dir[count_dir].symbol != NULL; count_dir++)
				{
					if (format[count + 1] == dir[count_dir].symbol[0])
					{
						total += dir[count_dir].print(args);
						match = 1;
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
*/

int _printf(const char *format, ...)
{
    va_list args;
    int count = 0, count_dir, total = 0, match;
    dir dir[] = {
        {"c", count_char},
        {"s", count_string},
        {"%", count_percent},
        {NULL, NULL}
    };

    if (!format)  /* Safe: do nothing if format is NULL */
        return 0;

    va_start(args, format);

    while (format[count] != '\0')
    {
        if (format[count] == '%')
        {
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
            if (match)
                count += 2;  /* Skip the specifier */
            else
            {
                write(1, &format[count], 1);  /* Print unknown % literally */
                total++;
                count++;
            }
        }
        else
        {
            write(1, &format[count], 1);  /* Print regular char */
            total++;
            count++;
        }
    }

    va_end(args);
    return total;
}
