#include "holberton.h"

/**
* _is_alpha -  manage case with % and ' ' (spaces)
*@c: algo
* Return: int
*/
int _is_alpha(char c)
{
	if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
	{
		return (0);
	}
	return (1);
}

/**
 * rot13 - change the chars
 * @rot13: the string of change
 * Return: writed chars
 */
int rot13(char *rot13)
{

	int i, j;
	char c;

	char src[] = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";
	char new[] = "nNoOpPqQrRsStTuUvVwWxXyYzZaAbBcCdDeEfFgGhHiIjJkKlLmM";

	for (i = 0; rot13[i] != '\0'; i++)
	{

		if (rot13[i] == ' ')
		{
			c = ' ';
			write(1, &c, 1);
		}
		else if (!_is_alpha(rot13[i]))
			write(1, &rot13[i], 1);
		else
		{
			for (j = 0; src[j] != '\0'; j++)
			{
				if (src[j] == rot13[i])
				{
					c = new[j];
					write(1, &c, 1);
					break;
				}
			}
		}
	}
	j += 1;
	return (j);
}

/**
 * reverse_array - that says everything
 * @a: array to reverse
 * Return: writed chars
 */
int reverse_array(char *a)
{
	int i, len;

	i = 0;
	len = 0;

	if (!a)
		return (0);
	while (a[i] != '\0')
	{
		len++;
		i++;
	}
	for (i = len - 1; i >= 0; i--)
	{
		write(1, &a[i], 1);
	}
	return (len);
}
