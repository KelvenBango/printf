#include "main.h"

/**
 * spec_eng - calls the correct print function and returns a string
 *
 * @list: the va_list object
 * @data: the parsed complete specifier
 * @buffer: the main buffer
 *
 * Retrun: a string
 */
int spec_eng(va_list, spec_data_t *data, pf_buf_t *buffer)
{
	pf_buf_t *tmp;
	int len = 0, i, j = 0;
	specs_t specs[] = {
		{'c', store_char},
		{'s', store_string},
		{'d', store_int},
		{'i', store_int},
		{'u', store_uint},
		{'o', store_uoct},
		{'x', store_lowuhex},
		{'X', store_upuhex},
		{'r', store_rev},
		{'R', store_rot13},
		{'b', store_binary},
		{'S', store_strnop},
		{'p', store_ptr},
		{0, NULL}
	};

	for (i = 0; specs[i].spec; i++)
	{
		if (data->fmt_spec == specs[i].spec)
		{
			tmp = specs[i]. func(list, data);
			if (tmp)
			{
				while (j < tmp->len)
					pf_buf_t_add_char(buffer, tmp->buf[j++]);
				len = tmp->len;
				pf_buf_t_delete(tmp);
			}
		}
	}
	return (len);
}
	
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
