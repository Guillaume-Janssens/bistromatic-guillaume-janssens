/*
** EPITECH PROJECT, 2020
** bistromatic
** File description:
** multiplication
*/

#include "include/my.h"
#include <stdlib.h>
#include <stdio.h>

char *adapt(char *result, int i, int base)
{
    if (result[i] > '0' + base - 1) {
        result[i] -= base;
        result[i + 1] += 1;
    }
    return (result);
}

char *my_multiplication(char *result, int i, int nb, int base)
{
    result[i] += (nb % base);
    if (result[i] < '0')
        result[i] += '0';
    result = adapt(result, i, base);
    result[i + 1] += (nb / base);
    result = adapt(result, i + 1, base);    
    return (result);
}

char *my_end(char *result, int i, int base, int temp_result)
{
    result[i - 1] += '0';
    if (temp_result / base >= 1)
        result[i + 2] = '\0';
    else
        result[i + 1] = '\0';
    return (result);
}

char *infin_mult(char *nb1, char *nb2, int base)
{
    int val1;
    int val2;
    int i = 0;
    int j = 0;
    int temp_result = 0;
    char *result = malloc(sizeof(char) * (my_strlen(nb1) + my_strlen(nb2) + 1));

    while (nb1[i] != '\0') {
        val1 = nb1[i] - '0';
        j = 0;
        while (nb2[j] != '\0') {
            val2 = nb2[j] - '0';
            temp_result = val1 * val2;
            result = my_multiplication(result, i + j, temp_result, base);
            j += 1;
        }
        i += 1;
    }
    result = my_end(result, i + j, base, temp_result);
    return (my_revstr(result));
}
