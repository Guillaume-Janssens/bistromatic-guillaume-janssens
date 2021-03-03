/*
** EPITECH PROJECT, 2020
** evalexpr
** File description:
** my_itoa, transform int in char*
*/

#include <stdlib.h>
#include "my.h"

int absolute_value(int nb)
{
    if (nb < 0)
        nb = nb * -1;
    return (nb);
}

char *my_nbr_array(int nb, char *buffer, int *count)
{
    if (nb < 0) {
        buffer[*count] = '-';
        *count += 1;
        nb = nb * -1;
    }
    if (nb > 9) {
        buffer = my_nbr_array(nb / 10, buffer, count);
    }
    nb = nb % 10;
    buffer[*count] = nb + 48;
    *count += 1;
    buffer[*count] = '\0';
    return (buffer);
}

char *my_itoa(int value)
{
    char *buffer;
    int count = 0;

    buffer = malloc(sizeof(char) * 11);
    my_nbr_array(value, buffer, &count);
    return (buffer);
}
