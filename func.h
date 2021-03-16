#ifndef FUNC_H
#define FUNC_H

/*function that verify option of type date for print*/
typedef struct op
{
    char *op;
    int (*f)
};

int (*get_print_func(char *s))(int);


#endif /*func_h*/
