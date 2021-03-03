/*
** EPITECH PROJECT, 2020
** test_evalexpres.c
** File description:
** evalexpres
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

void my_ops(char *str, array_t *cal, int nb)
{
    if (str[cal->count] != ')' && str[cal->count] != '\0') {
        cal->pol[cal->ar + 1] = malloc(sizeof(char) * 2);
        cal->pol[cal->ar + 1][cal->nb] = str[cal->count];
        cal->pol[cal->ar + 1][cal->nb + 1] = '\0';
        cal->count += 1;
        nbs(str, cal, nb);
        if (str[cal->count] == '('  || str[cal->count] == ')') {
            cal->count -= 2;
            my_inpar(str, cal, nb);
        }
        cal->ar += 1;
        if (str[cal->count - 3] != ')')
            my_array_swap(cal);
    } else
        cal->count += 1;
}

void my_inpar(char *str, array_t *cal, int nb)
{
    if (str[cal->count] == '\0')
        cal->count -= 2;
    cal->count += 2;
    while (str[cal->count] != ')' && str[cal->count] != '\0') {
        if (str[cal->count] <= ('0' + nb) && str[cal->count] >= '0')
            nbs(str, cal, nb);
        if (!(str[cal->count] == '(')) {
            my_ops(str, cal, nb);
        }
    }
}

void my_par_is_first(char *str, array_t *cal, int nb)
{
    while (str[cal->count] != ')' && str[cal->count] != '\0') {
        if (str[cal->count] <= ('0' + nb) && str[cal->count] >= '0')
            nbs(str, cal, nb);
        if (!(str[cal->count] == '(')) {
            my_ops(str, cal, nb);
        } else {
            my_pre_inpar(str, cal, nb);
        }
    }
}

char *eval_expr(char const *str, int nb)
{
    array_t *cal = malloc(sizeof(array_t));
    char *s = my_strdup(str);

    cal->ar = 0;
    cal->count = 0;
    cal->result = 0;
    cal->pol = malloc(sizeof(char *) * (my_nb_nb(s) * 2 + 2));
    while (s[cal->count] != '\0') {
        if ((s[cal->count] <= ('0' + nb) && s[cal->count] >= '0'))
            nbs(s, cal, nb);
        if (!(s[cal->count + 1] == '(' || s[cal->count] == '(')) {
            my_ops(s, cal, nb);
        } else {
            my_pre_inpar(s, cal, nb);
        }
    }
    cal->pol[cal->ar] = NULL;
    return (my_pre_use_doop(cal->pol, nb));
}
