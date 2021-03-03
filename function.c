/*
** EPITECH PROJECT, 2020
** do_op
** File description:
** pointeur de fonction
*/

#include <stdlib.h>
#include <stdio.h>
#include "bistromatic.h"
#include "my.h"

char *addition(char *nb1,char *nb2, int nb)
{
    char *result;

    nb1= my_revstr(nb1);
    nb2 = my_revstr(nb2);
    if (my_strlen(nb1) > my_strlen(nb2))
        nb2 = my_adjust_num(nb2, my_strlen(nb1));
    else if (my_strlen(nb2) > my_strlen(nb1))
        nb1 = my_adjust_num(nb1, my_strlen(nb2));
    result = my_choice(nb1, nb2, nb);
    return (result);
}

char *soustraction(char *nb1,char *nb2, int nb)
{
    char *result;
    char *nb2_bis = malloc(sizeof(char) * (my_strlen(nb2) + 2));
    int i = 0;

    nb2_bis[0] = '-';
    while (nb2[i] != '\0') {
        nb2_bis[i + 1] = nb2[i];
        i += 1;
    }
    nb2_bis[i + 1] = '\0';
    nb1= my_revstr(nb1);
    nb2 = my_revstr(nb2_bis);
    if (my_strlen(nb1) > my_strlen(nb2))
        nb2 = my_adjust_num(nb2, my_strlen(nb1));
    else if (my_strlen(nb2) > my_strlen(nb1))
        nb1 = my_adjust_num(nb1, my_strlen(nb2));
    result = my_choice(nb1, nb2, nb);
    return (result);
}

char *modulos(char *nb1, char *nb2, int nb)
{
    char *result;

    if (nb2[0] == '0') {
        my_putstr(ERROR_MSG);
        exit(EXIT_USAGE);
    }
    nb1 = my_is_it_neg(nb1);
    nb2 = my_is_it_neg(nb2);
    result = my_infin_mod(nb1, nb2, nb);
    if (result[0] == '\0')
        return ("0");
    return (result);
}

char *multiplication(char *nb1,char *nb2, int nb)
{
    if (nb1[0] == '-' || nb2[0] == '-') {
        if (nb1[0] == '-' && nb2[0] == '-') {
            nb1 = my_is_it_neg(nb1);
            nb2 = my_is_it_neg(nb2);
            return (my_supr0(infin_mult(my_revstr(nb1), my_revstr(nb2), nb)));
        } else {
            nb1 = my_is_it_neg(nb1);
            nb2 = my_is_it_neg(nb2);
            return (my_revstr(my_p_neg(my_revstr(my_supr0(infin_mult(
                                    my_revstr(nb1), my_revstr(nb2), nb))))));
        }
    }
    return (my_supr0(infin_mult(my_revstr(nb1), my_revstr(nb2), nb)));
}

char *division(char *nb1,char *nb2, int nb)
{
    if (nb2[0] == '0') {
        my_putstr(ERROR_MSG);
        exit(EXIT_USAGE);
    }
    if (nb1[0] == '-' || nb2[0] == '-') {
        if (nb1[0] == '-' && nb2[0] == '-') {
            nb1 = my_is_it_neg(nb1);
            nb2 = my_is_it_neg(nb2);
            return (my_infin_div(nb1, nb2, nb));
	} else {
            nb1 = my_is_it_neg(nb1);
            nb2 = my_is_it_neg(nb2);
            return (my_revstr(my_p_neg(my_revstr(my_infin_div(nb1, nb2, nb)))));
        }
    }
    return (my_infin_div(nb1, nb2, nb));
}
