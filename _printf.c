#include "holberton.h"
/**
 * _printf - simple funtion to write chars in stdout
 * @format: string to write
 * Return: integer
 */
int _printf(const char *format, ...)
{
	int cprinted = 0,  i = 0;
	char c, *vc = NULL;

	va_list(arglist);
	if (*format == '\0') /*se valida el string de entrada */
		return (1);
		va_start(arglist, format);

	for ( ; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			++i;
			if (format[i] == 'd' || format[i] == 'i')
				cprinted += (get_print_int(format[i])((va_arg(arglist, int))));
			else if (format[i] == 's' || format[i] == 'c' || format[i] == 'R'
					|| format[i] == '%' || format[i] == 'r')
			{
				if (format[i] == '%')
					cprinted += (get_print_char(format[i])(vc));
				else
					cprinted += (get_print_char(format[i])((va_arg(arglist, char *))));
			}
			else
			{
				c = format[i - 1];
				write(1, &c, 1);
				cprinted++;
				--i;
			}
		}
		else
		{
			write(1, &format[i], 1);
			cprinted++;
		}
	}
	va_end(arglist);
return (cprinted);
}
