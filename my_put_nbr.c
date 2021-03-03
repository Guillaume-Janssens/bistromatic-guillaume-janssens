/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** putnbr
*/

#include <unistd.h>
#include "my.h"

int my_put_nbr(int nb)
{
    char c;
    if (nb == -2147483648) {
        my_putstr("-2147483648");
        return (0);
    }
    if (nb < 0) {
        write(1, "-", 1);
        nb = nb * -1;
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
    }
    c = (nb % 10 + 48);
    write(1, &c, 1);
    return (0);
}
