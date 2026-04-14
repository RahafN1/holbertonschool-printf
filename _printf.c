#include "main.h"
#include <unistd.h>

/**
 * _printf - prints formatted output
 * @format: string containing text and format specifiers
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int i = 0;

	if (!format)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;

			if (format[i] == 'c')
				count += print_char(args);
			else if (format[i] == 's')
				count += print_string(args);
			else if (format[i] == '%')
			{
				write(1, "%", 1);
				count++;
			}
			else if (format[i] == '\0')
			{
				va_end(args);
				return (-1);
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}

		i++;
	}

	va_end(args);

	return (count);
}
