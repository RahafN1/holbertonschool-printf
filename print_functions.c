#include "main.h"
#include <unistd.h>

/**
 * print_char - adds a character to buffer
 * @args: va_list containing the character
 * @buffer: output buffer
 * @buf_idx: current index in buffer
 *
 * Return: number of characters added
 */
int print_char(va_list args, char *buffer, int *buf_idx)
{
	char c;

	c = (char)va_arg(args, int);
	buffer[(*buf_idx)++] = c;
	return (1);
}

/**
 * print_string - adds a string to buffer
 * @args: va_list containing the string
 * @buffer: output buffer
 * @buf_idx: current index in buffer
 *
 * Return: number of characters added
 */
int print_string(va_list args, char *buffer, int *buf_idx)
{
	char *str;
	int len;

	len = 0;
	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	while (str[len])
	{
		buffer[(*buf_idx)++] = str[len];
		len++;
	}
	return (len);
}

/**
 * print_int - adds an integer to buffer
 * @args: va_list containing the integer
 * @buffer: output buffer
 * @buf_idx: current index in buffer
 *
 * Return: number of characters added
 */
int print_int(va_list args, char *buffer, int *buf_idx)
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
		buffer[(*buf_idx)++] = '-';
		count++;
		if (n == -2147483648)
		{
			print_string_literal("2147483648", buffer, buf_idx);
			return (count + 10);
		}
		n = -n;
	}
	while (n / divisor >= 10)
		divisor *= 10;
	while (divisor > 0)
	{
		digit = n / divisor + '0';
		buffer[(*buf_idx)++] = digit;
		count++;
		n %= divisor;
		divisor /= 10;
	}
	return (count);
}
