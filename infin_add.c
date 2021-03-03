/*
** EPITECH PROJECT, 2020
** infin_add
** File description:
** add nb infini
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "infin_add.h"

int check_my_soustrac(char *str)
{
    int a = 1;
    int count = 0;

    while (str[count] != '-' && str[count] != '\0')
        count += 1;
    while (str[count] == '-' && str[count] != '\0') {
        a = a * -1;
        count += 1;
    }
    if (a > 0)
        return (1);
    else
        return (-1);
}

char *my_adjust_num(char *a, int n)
{
    char *dest = malloc(sizeof(char) * n + 5);
    int count = 0;
    int count_bis = 0;

    while (a[count_bis] != '\0') {
        if (a[count_bis] == '-') {
            dest[count] = '0';
            dest[count + 1] = '-' ;
            count += 2;
        }
        else {
            dest[count] = a[count_bis];
            count += 1;
        }
        count_bis += 1;
    }
    while (count < n) {
        dest[count] = '0';
        count += 1;
    }
    dest[count] = '\0';
    return (dest);
}

char *my_choice(char *a, char *b, int nb)
{
 
    int n = check_my_soustrac(a);
    int c = check_my_soustrac(b);

    if (n == 1 && c == 1) {
        return (my_supr0(infin_add(a, b, nb)));
    }
    else if (n == -1 && c == -1) {
        return (my_p_neg(my_pre_use_add(a, b, nb)));
    }
    else {
        return (my_compare_bis(a, b, n, c, nb));
    }
}
