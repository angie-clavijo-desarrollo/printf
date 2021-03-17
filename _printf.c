#include "holberton.h"
/**
 * _printf - voy a llorar nuestro primer proyecto en grupo
 * @format: puntero a la cadena a imprimir en pantalla
 * Return: integer
 */
int _printf(const char *format, ...)
{
	int cprinted = 0,  i = 0;
	char  *vc = NULL;

	va_list(arglist);
	if (*format == '\0') /*se valida el string de entrada */
		return (-1);
		va_start(arglist, format);
	for ( ; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			cprinted++;
		}
		else
		{
			++i;
			if (format[i] == 'd' || format[i] == 'i')
			{
				cprinted += (get_print_int(format[i])((va_arg(arglist, int))));
			}
			else if (format[i] == 's' || format[i] == 'c' || format[i] == '%')
			{
				if (format[i] == '%')
					cprinted += (get_print_char(format[i])(vc));
				else
				{
					cprinted += (get_print_char(format[i])((va_arg(arglist, char *))));
				}
			}
			else
			{
				--i;
				write(1, &format[i], 1);
			}
		}
	}
	va_end(arglist);
return (cprinted);
}
