/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main bistromatic
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int my_h(void)
{
    my_putstr("USAGE\n./calc base operators size_read\n\nDESCRIPTION\n- base: all the symbols of the base\n- operators: the symbols for the parentheses and the 5 operators\\n- size_read: number of characters to be read ");
    return (0);
}

int main(int argc, char **argv)
{
    char *cpy;
    int base;
    char *result;
    char *buff = error(argv[1], argv[2], my_getnbr(argv[3]), argc);

    if (argv[1][1] == '-' && argv[1][2] == 'h') {
        my_h;
        return (0);
    }
    else {
    cpy = malloc(sizeof(char) * (my_strlen(buff) + 1));
    cpy = my_numbers(argv[1], buff, cpy);
    cpy = my_operators(argv[2], buff, cpy);
    base = size_base(argv[1]);
    result = eval_expr(cpy, base);
    cpy = my_combiner(argv[1], argv[2], cpy);
    result = my_translator(cpy, result);
    my_putstr(result);
    return (0);
    }
}
