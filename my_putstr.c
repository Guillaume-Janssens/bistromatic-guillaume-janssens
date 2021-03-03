/*
** EPITECH PROJECT, 2020
** putstr
** File description:
** prints displays a string made of char
*/

#include <unistd.h>
#include "my.h"

void my_putstr(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i += 1;
    }
}
