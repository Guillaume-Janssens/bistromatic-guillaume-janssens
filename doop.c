/*
** EPITECH PROJECT, 2020
** do_op
** File description:
** pointeur de fonction
*/

#include <stdlib.h>
#include "my.h"

int check_my_sous(char *str)
{
    int a = 1;
    int count = 0;

    while (str[count] != '-')
        count += 1;
    while (str[count] == '-') {
        a = a * -1;
        count += 1;
    }
    if (a > 0)
        return (1);
    else
        return (2);
}

char *my_doop(char *a1, char *a2, char *a3, int nb)
{
    char *str = "+-*/%";
    int count = 0;
    char *result;
    int x = 0;
    char *(*listeFonctions[5])(char *, char *, int) = {addition,
                                                    soustraction,
                                                    multiplication,
                                                    division,
                                                    modulos};

    while (str[count] != '\0' && x != 1) {
        if (str[count] == a2[0])
            x = 1;
        count += 1;
    }
    if (count - 1 == 1)
        count = check_my_sous(a2);
    result = (listeFonctions[count - 1])(a1, a3, nb);
    return (result);
}
