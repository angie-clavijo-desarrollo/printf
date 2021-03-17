#include "holberton.h"
/**
*get_print_int - name function to called type dates
* @s: parameter type char
* Return: value of op_s the pocision
*/
int (*get_print_int(char s))(int)
{
	i_int list[] = {
		{'d', print_integer},
		{'i', print_integer},
	};
	int i = 0;

	while (list[i].op != '\0')
	{
		if (list[i].op == s)
		{
			return ((list[i]).f);
		}
		i++;
	}
	return (0);
}
/**
*get_print_char - name function to called type dates
* @s: parameter type char
* Return: value of op_s the pocision
*/
int (*get_print_char(char s))(char *z)
{
	i_char list[] = {
		{'s', print_string},
		{'c', print_char},
		{'%', print_percent},
	};
	int i = 0;

	while (list[i].op != '\0')
	{
		if (list[i].op == s)
		{
			return ((list[i]).f);
		}
		i++;
	}
	return (0);
}
