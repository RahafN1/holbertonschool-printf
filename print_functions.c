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
/**
 * print_binary - prints an unsigned int in binary
 * @args: argument list
 *
 * Return: number of characters printed
 */
int print_binary(va_list args)
{
	unsigned int n;
	unsigned int divisor;
	int count;
	char digit;

	n = va_arg(args, unsigned int);
	count = 0;
	divisor = 1;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	/* find highest power of 2 */
	while (n / divisor >= 2)
		divisor *= 2;

	/* print digits */
	while (divisor > 0)
	{
		digit = (n / divisor) + '0';
		write(1, &digit, 1);
		count++;
		n %= divisor;
		divisor /= 2;
	}

	return (count);
}
/**
 * print_unsigned - prints unsigned int
 * @args: argument list
 *
 * Return: number of characters printed
 */
int print_unsigned(va_list args)
{
	unsigned int n;
	unsigned int divisor;
	int count;
	char digit;

	n = va_arg(args, unsigned int);
	count = 0;
	divisor = 1;

	while (n / divisor >= 10)
		divisor *= 10;

	while (divisor > 0)
	{
		digit = (n / divisor) + '0';
		write(1, &digit, 1);
		count++;
		n %= divisor;
		divisor /= 10;
	}

	return (count);
}
/**
 * print_octal - prints number in octal
 * @args: argument list
 *
 * Return: number of characters printed
 */
int print_octal(va_list args)
{
	unsigned int n;
	unsigned int divisor;
	int count;
	char digit;

	n = va_arg(args, unsigned int);
	count = 0;
	divisor = 1;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	while (n / divisor >= 8)
		divisor *= 8;

	while (divisor > 0)
	{
		digit = (n / divisor) + '0';
		write(1, &digit, 1);
		count++;
		n %= divisor;
		divisor /= 8;
	}

	return (count);
}
#include "main.h"

/**
 * print_hex - prints number in hexadecimal
 * @args: argument list
 * @uppercase: 1 for uppercase, 0 for lowercase
 *
 * Return: number of characters printed
 */
int print_hex(va_list args, int uppercase)
{
	unsigned int n;
	unsigned int divisor;
	int count;
	char *hex;
	char digit;

	n = va_arg(args, unsigned int);
	count = 0;
	divisor = 1;

	if (uppercase)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	while (n / divisor >= 16)
		divisor *= 16;

	while (divisor > 0)
	{
		digit = hex[n / divisor];
		write(1, &digit, 1);
		count++;
		n %= divisor;
		divisor /= 16;
	}

	return (count);
}
