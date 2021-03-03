/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** day8 task1
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src);

char *my_strdup(char const *str)
{
    char *cpy;
    int len = my_strlen((char *)str);

    cpy = malloc(sizeof(char) * (len + 1));
    if (str == NULL)
        return (NULL);
    my_strcpy(cpy, str);
    return (cpy);
}
