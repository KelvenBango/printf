#include "main.h"

/**
 * _printf - entry point for our main function
 *
 * @format: the format string
 *
 * Return: the number of characters printed (excluding the NULL byte)
 */
int _printf(const char *format, ...)
{
	va_list list;
	int i = 0, len = 0;
	pf_buf_t *buffer;
	int total_len = 0, tmp_len = 0;

	buffer = pf_buf_t_new(BUFSIZE);
	if (!buffer)
		return (0);

	va_start(list, format);

	if (!format)
		return (-1);

	len = _strlen((char *)format);
	while (format[i] && i < len)
	{
		while (format[i] && format[i] != '%')
		{
			pf_buf_t_add_char(buffer, format[i++]);
			total_len++;
		}

		if (format[i] == '%' && len > 1)
		{
			tmp_len = format_parsing(&i, format, buffer, list);
			if (tmp_len == -1)
				return (-1);
			total_len += tmp_len;
			tmp_len = 0;
		}
		i++;
	}
	pf_buf_t_print(buffer);
	va_end(list);
	pf_buf_t_delete(buffer);
	return (total_len);
}
