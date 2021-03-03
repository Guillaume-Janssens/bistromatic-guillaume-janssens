/*
** EPITECH PROJECT, 2020
** my_str_isnum
** File description:
** verifi if the str is a nbr
*/

int my_str_isnum(char *str, int nb)
{
    int count = 0;

    while (str[count] != '\0') {
        if ((str[count] <= 47 ||
                str[count] >= (58 + nb)) && (str[count] != '-'))
            return (0);
        count += 1;
    }
    return (1);
}
