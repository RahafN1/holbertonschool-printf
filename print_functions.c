#include "main.h"
#include <unistd.h>

/**
 * print_char - prints a character
 * @args: argument list
 *
 * Return: number of characters printed (1)
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	write(1, &c, 1);

	return (1);
}

/**
 * print_string - prints a string
 * @args: argument list
 *
 * Return: length of string printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int len = 0;

	if (!str)
		str = "(null)";

	while (str[len])
	{
		write(1, &str[len], 1);
		len++;
	}

	return (len);
}
