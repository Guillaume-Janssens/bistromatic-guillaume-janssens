/*
** EPITECH PROJECT, 2020
** base and op
** File description:
** gets the information fiven as 
** parameter to set the base and operators
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int size_base(char *argv)
{
    int i = 0;

    i = my_strlen(argv);
    return (i);
}

char *my_replacer(char *argv, char const *buff, char *cpy, char *str)
{
    int i = 0;
    int n = 0;

    while (str[i] != '\0') {
        while (buff[n] != '\0') {
            if (buff[n] == argv[i]) {
                cpy[n] = str[i];
            }
            n += 1;
        }
        n = 0;
        i += 1;
    }
    return (cpy);
}

char *my_numbers(char *argv1, char const *buff, char *cpy)
{
    char x = '0';
    int n = 0;
    char *nums;
    
    nums = malloc(sizeof(char) * (my_strlen(argv1) + 1));
    while (n <= my_strlen(argv1) - 1) {
        nums[n] = x;
        n += 1;
        x += 1;
    }
    cpy = my_replacer(argv1, buff, cpy, nums);
    return (cpy);
}

char *my_operators(char *argv2, char const *buff, char *cpy)
{
    char op[] = "()+-*/%";

    cpy = my_replacer(argv2, buff, cpy, op);
    return (cpy);
}

char *my_reader(char *buff)
{
    int len = 0; 
    int offset = 0;
    
    while ((len = read(0, buff + offset,
                        99000 - offset)) > 0) {
        offset = offset + len;
    }
    buff[offset] = '\0';
    return (buff);
}
