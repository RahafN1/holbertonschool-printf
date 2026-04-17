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
	int len;
	unsigned char c;
	char *hex;
	char hi;
	char lo;

	hex = "0123456789ABCDEF";
	len = 0;
	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	while (str[len])
	{
		c = (unsigned char)str[len];
		if (c < 32 || c >= 127)
		{
			if (*buf_idx >= 1020)
				flush_buffer(buffer, buf_idx);
			buffer[(*buf_idx)++] = '\\';
			if (*buf_idx >= 1020)
				flush_buffer(buffer, buf_idx);
			buffer[(*buf_idx)++] = 'x';
			hi = hex[c / 16];
			lo = hex[c % 16];
			if (*buf_idx >= 1020)
				flush_buffer(buffer, buf_idx);
			buffer[(*buf_idx)++] = hi;
			if (*buf_idx >= 1020)
				flush_buffer(buffer, buf_idx);
			buffer[(*buf_idx)++] = lo;
			len += 4;
		}
		else
		{
			if (*buf_idx >= 1020)
				flush_buffer(buffer, buf_idx);
			buffer[(*buf_idx)++] = c;
			len++;
		}
	}
	return (len);
}
