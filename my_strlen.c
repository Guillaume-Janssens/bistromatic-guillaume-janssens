/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** calcul the leng of a str
*/

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i += 1;
    return (i);
}
