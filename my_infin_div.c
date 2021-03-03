/*
** EPITECH PROJECT, 2020
** bistro-matic
** File description:
** division de valeur de taille infini
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int my_compar(char *big, char *small)
{
    int i = 0;

    if (my_strlen(big) < my_strlen(small)) 
        return (1);
    else if (my_strlen(big) == my_strlen(small)) {
        while (big[i] == small[i] && big[i] != '\0')
            i += 1;
        if (big[i] < small[i])
            return (1);
        return(0);
    }
    return (0);
}

int div_step(char *rest, char *div, char *divisor, int start)
{
    int f = 1;
    int len = my_strlen(rest);

    if (rest[len - 1] == '0')
        rest[len - 1] = div[start];
    else
        rest[len] = div[start];
    f = my_compar(rest, divisor);
    return (f);
}

int my_first_div(char *rest, char *div, char *divisor)
{
    int len = 0;
    int f = 1;

    while (f > 0) {
        rest[len] = div[len];
        rest[len + 1] = '\0';
        f = my_compar(my_duprev(rest), my_duprev(divisor));
        len += 1;
    }
    return (len);
}

char *my_infin_div(char *div, char *divisor, int nb)
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
         if (f == 0)
            result[i] = my_rep(rest, divisor, nb);
        else
            result[i] = '0';
         f = div_step(rest, div, divisor, len  + i);
        i += 1;
        len = 1;
    }
    result[i] = '\0';
    return (result);
}

