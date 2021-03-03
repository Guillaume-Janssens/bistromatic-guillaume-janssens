/*
** EPITECH PROJECT, 2020
** bistro-matic
** File description:
** division de valeur de taille infini
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>

char *my_is_it_neg(char *av)
{
    char *a = av;
    int i = 0;

    if (av[0] == '-') {
	while (av[i] != '\0') {
            a[i] = av[i + 1];
            i += 1;
	}
        a[i] = '\0';
    }
    return (a);
}

char my_rep(char *rest, char *div, int nb)
{
    int f = 0;
    char i = '0';

    while (f == 0) {
        rest = my_strcpy(rest, soustraction(rest, div, nb));
        f = my_compar(rest, div);
        i += 1;
    }
    return (i);
}

char *my_infin_mod(char *div, char *divisor, int nb)
{
    char *rest = malloc(sizeof(char) * (my_strlen(div) + 1));
    char *result = malloc(sizeof(char) * (my_strlen(div) + 1));
    int len;
    int the_len = my_strlen(div);
    int f = 0;
    int i = 0;

    if (my_compar(div, divisor) == 1)
        return ("0");
    len = my_first_div(rest, div, divisor);
    while (the_len != 0) {
        the_len -= len;
        if (f == 0) {
            result[i] = my_rep(rest, divisor, nb);
            rest = rest;
        } else
            result[i] = '0';
        f = div_step(rest, div, divisor, len  + i);
        i += 1;
        len = 1;
    }
    rest[i] = '\0';
    return (rest);
}
