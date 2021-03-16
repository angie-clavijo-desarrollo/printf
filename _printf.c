#include "holberton.h"
/**
 * _printf - voy a llorar nuestro primer proyecto en grupo
 * @format: puntero a la cadena a imprimir en pantalla
 * Return: integer
 */
int _printf(const char *format, ...)
{
	int bp, vi, cprinted = 0, vc;
	void *vp;
	char *copy; /* se declara una variable como copia de la cadena a imprimir */
	va_list(argumentos);
	if (*format == '\0') /*se valida el string de entrada */
		return (1);
	copy = (char *)format; /* se copia la direccion de la cadena de entrada */
	va_start(argumentos, format);
	for (; *copy != '\0'; copy++)
	{
		if (*copy == '%')
		{
			++copy;
				cprinted += (get_print_func(*copy)(va_arg(argumentos, int));
		}
		write(1, copy, 1);
		cprinted++;
	}
	va_end(argumentos);
	return (cprinted);
}

int main(void)
{
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	return (0);
}
