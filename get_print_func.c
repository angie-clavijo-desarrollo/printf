#include "holberton.h"
#include "func.h"
/**
 *get_print_func - name function to called type dates
 * @s: parameter type char
 * Return: value of op_s the pocision
 */
int (*get_print_func(char *s))(int)
{
	op_i op_s[] = {
		{"s", print_string},
		{"c", print_char},
		{"d", print_integer},
		{"i", print_integer},
		{NULL, NULL};
		int i = 0;
	}
		while (op_s[i]->op != NULL)
		{
			if (op_s[i]->op == *s)
			{
				return (op_s[i]->f);
			}
			i++
		}
	return (NULL);
}
