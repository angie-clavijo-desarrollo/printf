#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

/*function that produce output according format*/
int _printf(const char *format, ...);

/* _strlen - count spaces */
int _strlen(char *s);

/*funtion to print chars */
int print_char(char *vc);

/*funtion to print strings */
int print_string(char *vp);

/*funtion to print numbers */
int print_integer(int vi);

/* funtion to obtain  identifier funtion */
int (*get_print_int(char))(int);

/* funtion to obtain  identifier funtion */
int (*get_print_char(char))(char *);

/* funtion to write a percent in stdout */
int print_percent(char *s);

int rot13(char *rot13);

int reverse_array(char *a);

/**
 * struct identchar  - Struct  to print
 * @op: The  identifier a operator
 * @f: The function associated
 */
typedef struct identchar
{
	char op;
	int (*f)(char *);
} i_char;

/**
 * struct identinteger  - Struct  to print
 * @op: The  identifier a operator
 * @f: The function associated
 */
typedef struct identinteger
{
	char op;
	int (*f)(int);
} i_int;

#endif
