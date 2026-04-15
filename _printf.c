#include "main.h"
#include <unistd.h>

/**
 * print_char - prints a single character
 * @args: va_list containing the character to print
 *
 * Return: number of characters printed (always 1)
 */
int print_char(va_list args)
{
	char c;

	c = (char)va_arg(args, int);
	write(1, &c, 1);
	return (1);
}

/**
 * print_string - prints a string
 * @args: va_list containing the string to print
 *
 * Return: number of characters printed
 */
int print_string(va_list args)
{
	char *str;
	int len;

	len = 0;
	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	while (str[len])
	{
		write(1, &str[len], 1);
		len++;
	}
	return (len);
}
#include "main.h"

/**
 * print_number - formats and prints a number string based on parameters
 * @str: string representation of the number
 * @params: pointer to struct containing formatting options
 *
 * Return: number of characters printed
 */

#include "main.h"
#include <unistd.h>

/**
 * print_int - prints an integer
 * @n: number to print
 *
 * Return: number of characters printed
 */

int print_int(int n)
{
	unsigned int num;
	int count;
	char c;

	count = 0;

	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		num = -n;
	}
	else
	{
		num = n;
	}

	if (num / 10)
		count += print_int(num / 10);

	c = (num % 10) + '0';
	write(1, &c, 1);
	count++;

	return (count);
}


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

	count = 0;
	i = 0;
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
				va_end(args);
				return (-1);
			}
			if (format[i] == 'c')
				count += print_char(args);
			else if (format[i] == 's')
				count += print_string(args);
			else if (format[i] == '%')
			{
				write(1, "%", 1);
				count++;
			}
			else if (format[i] == 'd' || format[i] == 'i')
				count += print_int(va_arg(args, int));
			else
			{
				write(1, &format[i - 1], 1);
				write(1, &format[i], 1);
				count += 2;
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
