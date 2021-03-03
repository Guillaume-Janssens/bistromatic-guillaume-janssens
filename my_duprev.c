/*
** EPITECH PROJECT, 2020
** bistromatic
** File description:
** revers and duplic
*/

#include <stdlib.h>
int my_strlen(char const *str);

char *my_revstr(char *str);

char *my_strcpy(char *dest, char const *src);

char *my_duprev(char const *str)
{
    char *cpy;
    int len = my_strlen((char *)str);

    cpy = malloc(sizeof(char) * (len + 1));
    if (str == NULL)
        return (NULL);
    my_strcpy(cpy, str);
    my_revstr(cpy);
    return (cpy);
}
