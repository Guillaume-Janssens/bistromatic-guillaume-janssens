/*
** EPITECH PROJECT, 2020
** base and op
** File description:
** gets the information fiven as 
** parameter to set the base and operators
*/

#include <stdio.h>
#include <stdlib.h>

int my_strlen(char *str);

char *my_base_op(char *argv)
{
    char *op;
    int i = 0;

    op = malloc(sizeof(char) * 8);
    while (argv[i] != '\0') {
        op[i] = argv[i];
        i += 1;
    }
    op[i] = '\0';
    printf("[%s]\n", op);
    return (op);
}

int size_base(char *argv)
{
    int i = 0;

    i = my_strlen(argv);
    printf("%d\n", i);
    return (i);
}

int main(int argc, char **argv)
{
    int i = 0;
    if (argc >= 2) {
    my_base_op(argv[2]);
    i = size_base(argv[1]);
    }
    return (i);
}
