#include "holberton.h"
/**
 * _printf - voy a llorar nuestro primer proyecto en grupo
 * @format: puntero a la cadena a imprimir en pantalla
 * Return: integer
 */
int _printf(const char *format, ...)
{
	int cprinted = 0, vp, i = 0;
	char c, *vc;

	va_list(arglist);

	if (*format == '\0') /*se valida el string de entrada */
		return (1);

	va_start(arglist, format);

	for (; format[i] != '\0'; i++)
	{
			if (format[i] == '%')
			{
				++i;
				if(format[i] == 'd' || format[i] == 'i')
				{
					vp = (va_arg(arglist, int));
					cprinted += (get_print_int(format[i])(vp));
				}	
				else if (format[i] == 's' || format[i] == 'c')
				{
					vc = (va_arg(arglist, char *));
					cprinted += (get_print_char(format[i])(vc));
				}
			}
			else
			{
				c = format[i];
				write(1, &c, 1);
				cprinted++;
			}
	}
	va_end(arglist);
return (cprinted);
}
