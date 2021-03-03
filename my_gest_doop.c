/*
** EPITECH PROJECT, 2020
** eval exper
** File description:
** i receive the values and give it to do the operation
*/

#include <stdlib.h>
#include "my.h"

int my_strarr(char **str)
{
    int count = 0;

    while (str[count] != NULL)
        count += 1;
    return (count);
}

char **my_reapply(char **str)
{
    int count = 0;
    int count_bis = 0;
    char **dest = malloc(sizeof(char *) * my_strarr(str) + 1);
    int x = 0;

    dest[count_bis] = malloc(sizeof(char) * 11);
    while (str[count] != NULL) {
        if (x != 0) {
            x = 0;
            count_bis += 1;
            dest[count_bis] = malloc(sizeof(char) * 11);
        }
        while (str[count][x] != '\0') {
            dest[count_bis][x] = str[count][x];
            x += 1;
        }
        dest[count_bis][x] = '\0';
        count += 1;
    }
    dest[count_bis + 1] = NULL;
    return (dest);
}

char *my_pre_use_doop(char **str, int nb)
{
    int count = 0;
    int count_bis = 0;
    char *opp = "+-*/%";

    while (str[count] != NULL && str[count + 1] != NULL &&
            str[count + 2] != NULL) {
        count_bis = 0;
        while (str[count + 2][0] != opp[count_bis])
            count_bis += 1;
        if (my_str_isnum(str[count], nb) == 1 &&
            my_str_isnum(str[count + 1], nb) == 1 && count_bis < 5) {
            str[count + 2] = my_doop(str[count], str[count + 2],
                                            str[count + 1], nb);
            str[count][0] = '\0';
            str[count + 1][0] = '\0';
            str = my_reapply(str);
            count = 0;
        } else
            count += 1;
    }
    return (str[0]);
}
