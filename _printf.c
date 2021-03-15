#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

/**
 * print_number - print a number with _putchar
 * @n: the number to print
 * Return: none
 */
void print_number(int n)
{
	int i = 0, mod = 0;
	unsigned int num;
	char numero[8], c, sign;

	if (n < 0)
	{
		sign = '-';
		write(1, &sign, 1);
		num = -n;
	}
	else
	{
		num = n;
	}

	for (; num > 0 ; i++)
	{
		mod = num % 10;
		numero[i] = (char)mod;
		num /= 10;
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
	int i = 0, bp, vi, cprinted = 0;
	void *vp;
	char *copy; /* se declara una variable como copia de la cadena a imprimir */

	va_list(argumentos);
	if (*format == '\0') /*se valida el string de entrada */
		return (1);
	copy = (char *)format; /* se copia la direccion de la cadena de entrada */
	va_start(argumentos, format);
	for (; copy[i] != '\0'; copy++, cprinted++)
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
				++cprinted;
				++copy;
				break;
			case 's':
				vp = va_arg(argumentos, char *); /* vp valor a imprimir */
				bp = _strlen(vp);				 /*bp bytes a imprimir */
				write(1, vp, bp);
				cprinted += bp;
				++copy;
				break;
			case 'd':
				vi = (va_arg(argumentos, int)); /*vi valor a imprimir del entero */
				print_number(vi);
				cprinted += 1; /* revisar */
				++copy;
				break;
			case 'i':
				vi = (va_arg(argumentos, int)); /*vi valor a imprimir del entero */
				print_number(vi);
				cprinted += 1; /* revisar */
				++copy;
				break;
			}
		}
		write(1, copy, 1);
	}
	va_end(argumentos);
	/* printf("%d\n", cprinted);*/
	return (cprinted);
}
