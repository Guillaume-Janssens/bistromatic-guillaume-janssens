/*
** EPITECH PROJECT, 2020
** infin_add
** File description:
** add
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char *my_malloc(char *a, char *b)
{
    char *result;

    if (a <= b)
        result = malloc(sizeof(char) * my_strlen(b) + 2);
    else
        result = malloc(sizeof(char) * my_strlen(a) + 2);
    if (result == NULL)
	    my_malloc(a, b);
    return (result);
}

char *infin_add(char *a, char *b, int nb)
{
    char *result = my_malloc(a, b);
    int retenu = 0;
    int count = 0;

    while (a[count] != '\0' && b[count] != '\0') {
	    result[count] = (a[count] - 48) + (b[count] - 48) + retenu;
	    retenu = 0;
        if ((result[count]) >= nb) {
            result[count + 1] += 1;
            result[count] = result[count] - nb;
            retenu = 1;
        }
        result[count] += 48;
        result[count + 1] += 48;
        count++;
    }
    if (retenu == 1)
        result[count] = 49;
    result[count + retenu] = '\0';
    result = my_revstr(result);
    return (result);
}

char *my_pre_use_add(char *a, char *b, int nb)
{
    a = my_supr0(my_revstr(a));
    b = my_supr0(my_revstr(b));
    if (my_strlen(a) > my_strlen(b)) {
        b = my_adjust_num(my_revstr(b), my_strlen(a));
        a = my_revstr(a);
    }
    else if (my_strlen(a) < my_strlen(b)) {
        a = my_adjust_num(my_revstr(a), my_strlen(b));
        b = my_revstr(b);
    }
    return (my_p_neg(my_revstr(infin_add(a, b, nb))));
}
