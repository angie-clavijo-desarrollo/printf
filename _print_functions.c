#include "holberton.h"

/* beging of the function print_char */
/**
* print_char - write a char in a stdout
* @vc: entry character
* Return: counter of printed chars
*/
int print_char(char *vc)
{
	write(1, &vc, 1);
	return (1);
}
/* end of the function*/

/* beging of the function print_string */
/**
* print_string - write a string in a stdout
* @vp: pointer to the string to print
* Return: counter of printed chars
*/
int print_string(char *vp)
{
	int bp = 0;

	bp = _strlen(vp); /*bp bytes a imprimir */
	write(1, vp, bp);
	return (bp);
}
/* end of the function*/

/* beging of funtion print_integer */
/**
* print_integer - write a integer in a stdout
* @n: integer to print
* Return: counter of printed chars
*/
int print_integer(int n)
{
	int size = 0, i = 0, mod = 0;
	unsigned int num;
	char numero[8], c;
	char sign;

	if (n < 0)
	{
		sign = '-';
		size += 1;
		numero[i] = sign;
		num = -n;
		write(1, &sign, 1);
	}
	else
	{
		num = n;
	}

	for (; num > 0; i++)
	{
		mod = num % 10;
		numero[i] = (char)mod;
		num /= 10;
	}
	size += i;
	i--;
	for (; i >= 0; i--)
	{
		c = (numero[i] + '0');
		write(1, &c, 1);
	}
	return (size);
}
/* end of the function*/

/* beging of the function _strlen */

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
/* end of the function*/

/**
* print_percent - write a percent sign in stdout
* @s: always void
* Return: number of printed chars
*/
int print_percent(char *s)
{
	char c = '%';

	(void)s; 
	write(1, &c, 1);
	return (1);
}