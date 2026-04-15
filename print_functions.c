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

/**
 * print_int - prints an integer
 * @args: va_list containing the integer to print
 *
 * Return: number of characters printed
 */
int print_int(va_list args)
{
	int n;
	int count;
	int divisor;
	int digit;

	n = va_arg(args, int);
	count = 0;
	divisor = 1;
	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		if (n == -2147483648)
		{
			write(1, "2147483648", 10);
			return (count + 10);
		}
		n = -n;
	}
	while (n / divisor >= 10)
		divisor *= 10;
	while (divisor > 0)
	{
		digit = n / divisor + '0';
		write(1, &digit, 1);
		count++;
		n %= divisor;
		divisor /= 10;
	}
	return (count);
}

