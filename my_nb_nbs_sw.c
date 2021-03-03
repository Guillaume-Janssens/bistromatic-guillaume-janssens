/*
** EPITECH PROJECT, 2020
** evalexpers
** File description:
** my_nb_nbs_sw.c
*/

#include <stdlib.h>
#include "my.h"

int my_nb_nb(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i += 1;
    return (i);
}

int my_nbs(char *str, int count, int nb)
{
    int i = 0;

    if (str[count] == '-')
        i += 1;
    while (str[count + i] <= ('0' + nb) && str[count + i] >= '0')
        i += 1;
    return (i);
}

void nbs(char *str, array_t *cal, int nb)
{
    cal->pol[cal->ar] = malloc(sizeof(char) *
                                (my_nbs(str, cal->count, nb) + 1));
    if (str[cal->count] == '-') {
        cal->pol[cal->ar][cal->nb] = str[cal->count];
        cal->nb += 1;
        cal->count += 1;
        str[cal->count - 1] = '0';
    }
    while (str[cal->count] <= ('0' + nb) && str[cal->count] >= '0') {
        cal->pol[cal->ar][cal->nb] = str[cal->count];
        cal->nb += 1;
        cal->count += 1;
    }
    cal->pol[cal->ar][cal->nb] = '\0';
    cal->nb = 0;
    cal->ar += 1;
}

void my_array_swap(array_t *cal)
{
    char *c;

    if (my_strlen(cal->pol[cal->ar - 3]) == 1) {
        if ((cal->pol[cal->ar - 3][0] == '+' ||
            cal->pol[cal->ar - 3][0] == '-') &&
            (cal->pol[cal->ar - 1][0] == '*' ||
            cal->pol[cal->ar - 1][0] == '/' ||
            cal->pol[cal->ar - 1][0] == '%')) {
            c = cal->pol[cal->ar - 3];
            cal->pol[cal->ar - 3] = cal->pol[cal->ar - 1];
            cal->pol[cal->ar - 1] = c;
            c = cal->pol[cal->ar - 3];
            cal->pol[cal->ar - 3] = cal->pol[cal->ar - 2];
            cal->pol[cal->ar - 2] = c;
        }
    }
}

void my_pre_inpar(char *str, array_t *cal, int nb)
{
    char mem;

    if (str[cal->count + 1] == ')') {
        mem = str[cal->count];
        my_inpar(str, cal, nb);
        cal->pol[cal->ar] = malloc(sizeof(char) * 2);
        cal->pol[cal->ar][0] = mem;
        cal->pol[cal->ar][1] = '\0';
        cal->ar += 1;
        cal->count += 1;
    } else if (cal->count == 1) {
        mem = str[cal->count];
        cal->count += 1;
        my_par_is_first(str, cal, nb);
        cal->pol[cal->ar] = malloc(sizeof(char) * 2);
        cal->pol[cal->ar][0] = mem;
        cal->pol[cal->ar][1] = '\0';
        cal->ar += 1;
        cal->count += 1;
    } else
        cal->count += 1;
}
