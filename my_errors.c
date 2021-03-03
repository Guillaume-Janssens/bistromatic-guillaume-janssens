/*
** EPITECH PROJECT, 2020
** bistromatic
** File description:
** gestion d'error
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "bistromatic.h"
#include "my.h"

char *get_expr(int size)
{
    char *expr;

    if (size <= 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_SIZE_NEG);
    }
    expr = malloc(sizeof(char) * size + 1);
    if (expr == NULL) {
        my_putstr(ERROR_MSG);
        exit(EXIT_MALLOC);
    }
    while (read(0, expr, size) != size) {
        my_putstr(ERROR_MSG);
        exit(EXIT_READ);
    }
    return (expr);
}

void check_ops(char *ops)
{
    if (my_strlen(ops) != 7) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_OPS);
    }
}

void check_base(char *b)
{
    if (my_strlen(b) < 2) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_BASE);
    }
}

char *error(char *base, char *ops, int  nb_dig, int ac)
{
    if (ac != 4) {
        my_putstr("Usage: ");
        my_putstr(base);
        my_putstr(" base ops\"()+_*/%\" exp_len\n");
        exit (EXIT_USAGE);
    }
    check_base(base);
    check_ops(ops);
    return (get_expr(nb_dig));
}
