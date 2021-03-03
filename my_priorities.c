/*
** EPITECH PROJECT, 2020
** priorities
** File description:
** checks if parenthesies are present in the 
**string and changes the string to deal with those priorities
*/

#include "my.h"
#include <stdlib.h>

char *my_del_blanc(int i, char *cpy)
{
    int x = i;
    
    while (cpy[i] != ')') {
        i += 1;
    }
    i += 1;
    while (cpy[i] != '\0') {
        cpy[x] = cpy[i];
        x += 1;
        i += 1;
    }
    cpy[x] = cpy[i];
    return (cpy);
}

char *my_cpy_to_cpy(char *cpy, char *prty)
{
    int i = 0;
    int x = 0;

    while (cpy[i] != '(')
        i += 1;
    while (prty[x] != '\0') {
        cpy[i] = prty[x];
        x += 1;
        i += 1;
    }
    cpy = my_del_blanc(i, cpy);
    return (cpy);
}

char *my_priorities(char *cpy, int base)
{
    int i = 0;
    int x = 0;
    char *prty;
    int n = 0;

    prty = malloc(sizeof(char) * (my_strlen(cpy) + 1));
    while (cpy[i] != '\0') {
        if (cpy[i] == ')') {
            while (cpy[i] != '(') {
                prty[x] = cpy[i];
                x += 1;
                i -= 1;
                n += 1;
            }
            prty[x] = cpy[i];
            prty = my_revstr(prty);
            prty[n + 1] = '\0';
            prty = eval_expr(prty, base);
            cpy = my_cpy_to_cpy(cpy, prty);
            cpy = my_priorities(cpy, base);
        }
        i += 1;
    }
    return (cpy);
}
