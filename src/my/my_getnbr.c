/*
** EPITECH PROJECT, 2023
** my_getnbr.c
** File description:
** my_getnbr.c
*/

#include "my.h"

int is_number(char const *string)
{
    for (unsigned long i = 0; string[i] != '\0'; i++)
        if (string[i] < '0' || string[i] > '9')
            return 0;
    return 1;
}

unsigned int my_getnbr(char const *string)
{
    unsigned int number = 0;

    for (unsigned long i = 0; string[i] != '\0'; i++)
        number = number * 10 + string[i] - '0';
    return number;
}
