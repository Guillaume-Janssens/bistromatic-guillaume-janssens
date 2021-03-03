/*
** EPITECH PROJECT, 2020
** Function strncpy
** File description:
** function strncpy
*/

int my_strlen(char *str);

char *my_revstr(char *str)
{
    int count = 0;
    int count2 = my_strlen(str) - 1;
    char b;

    while (count <= count2) {
        b = str[count];
        str[count] = str[count2];
        str[count2] = b;
        count += 1;
        count2 -= 1;
    }
    return (str);
}
