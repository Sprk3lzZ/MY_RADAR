/*
** EPITECH PROJECT, 2022
** number_to_string.c
** File description:
** number_to_string.c
*/

#include "my.h"
#include <stdlib.h>

static int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}

char *my_revstr(char *str)
{
    int a;
    int b;
    char *rev_str = str;
    int str_size = my_strlen(str);

    for (int i = 0; i < str_size / 2; i++) {

        b = str[str_size - i - 1];
        a = str[i];
        rev_str[i] = b;
        rev_str[str_size - i - 1] = a;
    }
    return rev_str;
}

char *my_strcar(char *str, char c)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    str[i] = c;
    str[i + 1] = '\0';
    return str;
}

char *number_to_string(int nb)
{
    char *str = malloc(sizeof(char) * 50);

    str[0] = '\0';
    do {
        my_strcar(str, nb % 10 + '0');
        nb /= 10;
    } while (nb > 0);
    return my_revstr(str);
}
