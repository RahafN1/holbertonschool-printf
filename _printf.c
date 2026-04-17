#include "main.h"
#include <unistd.h>

/**
 * _printf - produces output according to a format
 * @format: character string with conversion specifiers
 *
 * Return: number of characters printed, -1 on error
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count;
	int i;
	int buf_idx;
	char buffer[1024];

	count = 0;
	i = 0;
	buf_idx = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
			{
				write(1, buffer, buf_idx);
				va_end(args);
				return (-1);
			}
			if (format[i] == 'c')
				count += print_char(args, buffer, &buf_idx);
			else if (format[i] == 's')
				count += print_string(args, buffer, &buf_idx);
			else if (format[i] == 'S')
				count += print_string_special(args, buffer, &buf_idx);
			else if (format[i] == 'd' || format[i] == 'i')
				count += print_int(args, buffer, &buf_idx);
			else if (format[i] == 'b')
				count += print_binary(args, buffer, &buf_idx);
			else if (format[i] == 'u')
				count += print_unsigned(args, buffer, &buf_idx);
			else if (format[i] == 'o')
				count += print_octal(args, buffer, &buf_idx);
			else if (format[i] == 'x')
				count += print_hex(args, buffer, &buf_idx, 0);
			else if (format[i] == 'X')
				count += print_hex(args, buffer, &buf_idx, 1);
			else if (format[i] == '%')
			{
				buffer[buf_idx++] = '%';
				count++;
			}
			else
			{
				buffer[buf_idx++] = format[i - 1];
				buffer[buf_idx++] = format[i];
				count += 2;
			}
		}
		else
		{
			buffer[buf_idx++] = format[i];
			count++;
		}
		if (buf_idx >= 1020)
		{
			write(1, buffer, buf_idx);
			buf_idx = 0;
		}
		i++;
	}
	if (buf_idx > 0)
		write(1, buffer, buf_idx);
	va_end(args);
	return (count);
}
