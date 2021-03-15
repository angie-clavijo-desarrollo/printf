#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

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
void  *vp;
char *copy; /* se declara una variable como copia de la cadena a imprimir */
va_list(argumentos);
        if (*format == '\0')  /*se valida el string de entrada */
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
                                bp = _strlen(vp);                /*bp bytes a imprimir */
                                write(1, vp, bp);
                                ++copy;
                                break;

                                case 'd':
                                vi = (va_arg(argumentos, int) +'0'); /*vi valor a imprimir del entero */
                                /* printf("%d", vi); */
                                write(1, (&vi), 4);
                                ++copy;
                                break;

                        case 'i':
                                break;

                        }
                }
        write(1, copy, 1);
        }
    va_end(argumentos);

return (0);
}

