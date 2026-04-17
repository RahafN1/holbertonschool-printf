#include "main.h"
#include <unistd.h>

/**
 * flush_buffer - writes buffer to stdout and resets index
 * @buffer: output buffer
 * @buf_idx: current index in buffer
 */
void flush_buffer(char *buffer, int *buf_idx)
{
	if (*buf_idx > 0)
	{
		write(1, buffer, *buf_idx);
		*buf_idx = 0;
	}
}

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
	if (*buf_idx >= 1024)
		flush_buffer(buffer, buf_idx);
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
		if (*buf_idx >= 1024)
			flush_buffer(buffer, buf_idx);
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
	int j;
	char *s;

	n = va_arg(args, int);
	count = 0;
	divisor = 1;
	if (n < 0)
	{
		if (*buf_idx >= 1024)
			flush_buffer(buffer, buf_idx);
		buffer[(*buf_idx)++] = '-';
		count++;
		if (n == -2147483648)
		{
			s = "2147483648";
			j = 0;
			while (s[j])
			{
				if (*buf_idx >= 1024)
					flush_buffer(buffer, buf_idx);
				buffer[(*buf_idx)++] = s[j];
				j++;
			}
			return (count + 10);
		}
		n = -n;
	}
	while (n / divisor >= 10)
		divisor *= 10;
	while (divisor > 0)
	{
		if (*buf_idx >= 1024)
			flush_buffer(buffer, buf_idx);
		digit = n / divisor + '0';
		buffer[(*buf_idx)++] = digit;
		count++;
		n %= divisor;
		divisor /= 10;
	}
	return (count);
}

/**
 * print_binary - adds binary representation to buffer
 * @args: va_list containing the unsigned int
 * @buffer: output buffer
 * @buf_idx: current index in buffer
 *
 * Return: number of characters added
 */
int print_binary(va_list args, char *buffer, int *buf_idx)
{
	unsigned int n;
	unsigned int tmp;
	int count;
	int i;
	char bits[32];

	n = va_arg(args, unsigned int);
	count = 0;
	i = 0;
	if (n == 0)
	{
		if (*buf_idx >= 1024)
			flush_buffer(buffer, buf_idx);
		buffer[(*buf_idx)++] = '0';
		return (1);
	}
	tmp = n;
	while (tmp > 0)
	{
		bits[i++] = (tmp % 2) + '0';
		tmp /= 2;
	}
	while (i > 0)
	{
		if (*buf_idx >= 1024)
			flush_buffer(buffer, buf_idx);
		buffer[(*buf_idx)++] = bits[--i];
		count++;
	}
	return (count);
}

/**
 * print_unsigned - adds unsigned integer to buffer
 * @args: va_list containing the unsigned int
 * @buffer: output buffer
 * @buf_idx: current index in buffer
 *
 * Return: number of characters added
 */
int print_unsigned(va_list args, char *buffer, int *buf_idx)
{
	unsigned int n;
	unsigned int divisor;
	int count;
	int digit;

	n = va_arg(args, unsigned int);
	count = 0;
	divisor = 1;
	if (n == 0)
	{
		if (*buf_idx >= 1024)
			flush_buffer(buffer, buf_idx);
		buffer[(*buf_idx)++] = '0';
		return (1);
	}
	while (n / divisor >= 10)
		divisor *= 10;
	while (divisor > 0)
	{
		if (*buf_idx >= 1024)
			flush_buffer(buffer, buf_idx);
		digit = n / divisor + '0';
		buffer[(*buf_idx)++] = digit;
		count++;
		n %= divisor;
		divisor /= 10;
	}
	return (count);
}

/**
 * print_octal - adds octal representation to buffer
 * @args: va_list containing the unsigned int
 * @buffer: output buffer
 * @buf_idx: current index in buffer
 *
 * Return: number of characters added
 */
int print_octal(va_list args, char *buffer, int *buf_idx)
{
	unsigned int n;
	unsigned int tmp;
	int count;
	int i;
	char digits[32];

	n = va_arg(args, unsigned int);
	count = 0;
	i = 0;
	if (n == 0)
	{
		if (*buf_idx >= 1024)
			flush_buffer(buffer, buf_idx);
		buffer[(*buf_idx)++] = '0';
		return (1);
	}
	tmp = n;
	while (tmp > 0)
	{
		digits[i++] = (tmp % 8) + '0';
		tmp /= 8;
	}
	while (i > 0)
	{
		if (*buf_idx >= 1024)
			flush_buffer(buffer, buf_idx);
		buffer[(*buf_idx)++] = digits[--i];
		count++;
	}
	return (count);
}

/**
 * print_hex - adds hexadecimal representation to buffer
 * @args: va_list containing the unsigned int
 * @buffer: output buffer
 * @buf_idx: current index in buffer
 * @uppercase: 1 for uppercase, 0 for lowercase
 *
 * Return: number of characters added
 */
int print_hex(va_list args, char *buffer, int *buf_idx, int uppercase)
{
	unsigned int n;
	unsigned int tmp;
	int count;
	int i;
	char digits[32];
	char *hex;

	hex = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
	n = va_arg(args, unsigned int);
	count = 0;
	i = 0;
	if (n == 0)
	{
		if (*buf_idx >= 1024)
			flush_buffer(buffer, buf_idx);
		buffer[(*buf_idx)++] = '0';
		return (1);
	}
	tmp = n;
	while (tmp > 0)
	{
		digits[i++] = hex[tmp % 16];
		tmp /= 16;
	}
	while (i > 0)
	{
		if (*buf_idx >= 1024)
			flush_buffer(buffer, buf_idx);
		buffer[(*buf_idx)++] = digits[--i];
		count++;
	}
	return (count);
}

/**
 * print_string_special - prints string with non-printable chars as \xHH
 * @args: va_list containing the string
 * @buffer: output buffer
 * @buf_idx: current index in buffer
 *
 * Return: number of characters added
 */
int print_string_special(va_list args, char *buffer, int *buf_idx)
{
	char *str;
	int i;
	int count;
	unsigned char c;
	char *hex;

	hex = "0123456789ABCDEF";
	i = 0;
	count = 0;
	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	while (str[i])
	{
		c = (unsigned char)str[i];
		if (c < 32 || c >= 127)
		{
			if (*buf_idx >= 1024)
				flush_buffer(buffer, buf_idx);
			buffer[(*buf_idx)++] = '\\';
			if (*buf_idx >= 1024)
				flush_buffer(buffer, buf_idx);
			buffer[(*buf_idx)++] = 'x';
			if (*buf_idx >= 1024)
				flush_buffer(buffer, buf_idx);
			buffer[(*buf_idx)++] = hex[c / 16];
			if (*buf_idx >= 1024)
				flush_buffer(buffer, buf_idx);
			buffer[(*buf_idx)++] = hex[c % 16];
			count += 4;
		}
		else
		{
			if (*buf_idx >= 1024)
				flush_buffer(buffer, buf_idx);
			buffer[(*buf_idx)++] = c;
			count++;
		}
		i++;
	}
	return (count);
}
