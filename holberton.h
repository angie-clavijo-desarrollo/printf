#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
​
    /*function that produce output according format*/
    int _printf(const char *format, ...);
​
    /* _strlen - count spaces */
    int _strlen(char *s);
​
    /*funtion to print chars */
    int print_char(char *vc);
​
    /*funtion to print strings */
    int print_string(char *vp);
​
    /*funtion to print numbers */
    int print_integer(int vi);
​
    /**
 * struct_print  - Struct  to print
 * @idnetifier: The  identifier
 * @f: The function associated
 */
    typedef struct identifier
{
    char *op;
    int (*f)(int);
} op_i;

​
#endif /*head*/