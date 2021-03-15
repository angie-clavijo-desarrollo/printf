#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include "holberton.h"
/**
 * print_number - print a number with _putchar
 * @n: the number to print
 * Return: none
 */
int print_number(int n)
{
	int size, i = 0, mod = 0;
	unsigned int num;
	char numero[8], c, sign;

	if (n < 0)
	{
		sign = '-';
		numero[i] = sign;
		i++;
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
size = i;
i--;
	for (; i >= 0; i--)
	{
		c = (numero[i] + '0');
		write(1, &c, 1);
	}
return(size);
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
	int  bp, vi, cprinted = 0, vc;
	void *vp;
	char *copy; /* se declara una variable como copia de la cadena a imprimir */
	va_list(argumentos);
	if (*format == '\0') /*se valida el string de entrada */
		return (1);
	copy = (char *)format; /* se copia la direccion de la cadena de entrada */
	va_start(argumentos, format);
	for (; *copy != '\0'; copy++, cprinted++)
	{
		if (*copy == '%')
		{
			++copy;
			switch (*copy)
			{
			case 'c':
				vc = va_arg(argumentos, int); /* vp valor a imprimir */
				write(1, &vc, 1);
				break;
			case 's':
				vp = va_arg(argumentos, char *); /* vp valor a imprimir */
				bp = _strlen(vp);				 /*bp bytes a imprimir */
				write(1, vp, bp);
				cprinted += bp;
			case 'd':
				vi = (va_arg(argumentos, int)); /*vi valor a imprimir del entero */
				cprinted += print_number(vi);
				break;
			case 'i':
				vi = (va_arg(argumentos, int)); /*vi valor a imprimir del entero */
				print_number(vi);
				cprinted += 1; /* revisar */
				break;
			}
		}
	write(1, copy, 1);
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
