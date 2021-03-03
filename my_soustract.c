/*
** EPITECH PROJECT, 2020
** infin_add
** File description:
** soustract
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

char *my_sous(char *a, char *b, int nb)
{
    int count = 0;
    char *result = my_malloc(a, b);
    int retenu = 0;

    while (a[count] != '\0' && b[count] != '\0') {
        result[count] = (a[count] - 48) - (b[count] - 48) - retenu;
        retenu = 0;
        if ((result[count]) < 0) {
            result[count] = result[count] + nb;
            retenu = 1;
        }
        result[count] += 48;
        result[count + 1] += 48;
        count += 1;
    }
    result[count + retenu] = '\0';
    result = my_revstr(my_supr0(my_revstr(result)));
    return (result);
}

char *my_supr0(char *str)
{
    int count = 0;
    int count_bis = 0;
    char *dest = malloc(sizeof(char) * my_strlen(str) + 1);

    while ((str[count] == '-' || str[count] == '0') && str[count] != '\0' &&
           str[count + 1] != '\0')
        count += 1;
    while (str[count] != '\0') {
        dest[count_bis] = str[count];
        count += 1;
        count_bis += 1;
    }
    dest[count_bis] = '\0';
    return (dest);
}

char *my_pre_use(char *a, char *b, int nb)
{
    char *result;

    if (my_strlen(a) > my_strlen(b)) {
        b = my_adjust_num(my_revstr(b), my_strlen(a));
        a = my_revstr(a);
    }
    else if (my_strlen(a) < my_strlen(b)) {
	a = my_adjust_num(my_revstr(a), my_strlen(b));
        b = my_revstr(b);
    }
    result = my_sous(a, b, nb);
    return (result);
}

char *my_p_neg(char *result_bis)
{
    char *result;
    int i = 0;

    my_revstr(result_bis);
    result = malloc(sizeof(char) * (my_strlen(result_bis) + 2));
    result[0] = '-';
    while (result_bis[i] != '\0') {
        result[i + 1] = result_bis[i];
        i += 1;
    }
    result[i + 1] = '\0';
    return (my_revstr(result));
}

char *my_compare(char *a, char *b, int e, int f, int nb)
{
    int x = 0;
    int c = my_strlen(a);
    int d = my_strlen(b);
    char *result;

    while (c >= 0 && d >= 0 && x == 0) {
        if (a[c] > b[d]) {
            result = my_pre_use(a, b, nb);
            if (e == -1 && f == 1)
                result = my_p_neg(result);
            x = 1;
        }
        else if (a[c] < b[d]) {
            result = my_pre_use(b, a, nb);
            if (f == -1 && e == 1)
                result = my_p_neg(result);
            x = 1;
        }
        c--;
        d--;
    }
    if (x == 0)
        result = my_pre_use(a, b, nb);
    return (result);
}

char * my_compare_bis(char *a, char *b, int e, int f, int nb)
{
    a = my_supr0(my_revstr(a));
    b = my_supr0(my_revstr(b));    
    if (my_strlen(a) > my_strlen(b)) {
        b = my_adjust_num(my_revstr(b), my_strlen(a));
        a = my_revstr(a);
    } else if (my_strlen(a) < my_strlen(b)) {
        a = my_adjust_num(my_revstr(a), my_strlen(b));
        b = my_revstr(b);
    } else {
        my_revstr(a);
        my_revstr(b);
    }
    return (my_revstr(my_compare(a, b, e, f, nb)));
}
