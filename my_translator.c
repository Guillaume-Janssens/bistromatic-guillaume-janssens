/*
** EPITECH PROJECT, 2020
** my_translator.c
** File description:
** displays the result string using the initial charaters
*/

#include "my.h"
#include <stdlib.h>

char *my_combiner(char *argv1, char *argv2, char *cpy)
{
    int i = 0;
    int x = 0;

    while (argv1[i] != '\0') {
        cpy[i] = argv1[i];
        i += 1;
    }
    x = i;
    i = 0;
    while (argv2[i] != '\0') {
        cpy[x] = argv2[i];
        i += 1;
        x += 1;
    }
    cpy[x] = '\0';
    return (cpy);
}

char *my_translator(char *cpy, char *result)
{
    int i = 0;
    int x = 0;

    while (cpy[i] != '\0') {
        while (result[x] != '\0') {
            if (result[x] == i + 48)
                result[x] = cpy[i];
            x += 1;
        }
        i += 1;
        x = 0;
    }
    return (result);
}
