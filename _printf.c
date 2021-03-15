#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

void print_number(int n)
{
	int i = 0, mod = 0;
	char numero[8], c;

	for (; n > 0 ; i++)
	{
		mod = n % 10;
		numero[i] = (char)mod;
		n /= 10;
	}
	i--;
	for (; i >= 0; i--)
	{
		c = (numero[i] + '0');
		write(1, &c, 1);
	}
}

/**
 * _strlen - count spaces
 * @s: string
 * Return: n
 */
int _strlen(char *s)
{
	int n = 0;

	while (*s++ != '\0')
		n++;
	return (n);
}

/**
 * _printf - voy a llorar nuestro primer proyecto en grupo
 * @format: puntero a la cadena a imprimir en pantalla
 * Return: integer
 */

int _printf(const char *format, ...)
{
	int i = 0, bp, vi;
	void *vp;
	char *copy; /* se declara una variable como copia de la cadena a imprimir */

	va_list(argumentos);
		if (*format == '\0') /*se valida el string de entrada */
			return (1);
	copy = (char *)format; /* se copia la direccion de la cadena de entrada */
	va_start(argumentos, format);
	for (; copy[i] != '\0'; copy++)
	{
		if (*copy == '%')
		{
			bp = 0;
			++copy;
			switch (*copy)
			{
			case 'c':
				vp = va_arg(argumentos, int *); /* vp valor a imprimir */
				write(1, &vp, 1);
				++copy;
				break;
			case 's':
				vp = va_arg(argumentos, char *); /* vp valor a imprimir */
				bp = _strlen(vp);				 /*bp bytes a imprimir */
				write(1, vp, bp);
				++copy;
				break;
			case 'd':
				vi = (va_arg(argumentos, int)); /*vi valor a imprimir del entero */
				print_number(vi);
				++copy;
				break;
			case 'i':
				vi = (va_arg(argumentos, int)); /*vi valor a imprimir del entero */
				print_number(vi);
				++copy;
				break;
			}
		}
		write(1, copy, 1);
	}
	va_end(argumentos);
	return (0);
}
