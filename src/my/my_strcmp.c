/*
** EPITECH PROJECT, 2023
** my_strcmp.c
** File description:
** my_strcmp.c
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    unsigned int i = 0;

    while (s1[i] == s2[i] && s1[i])
        i++;
    return s1[i] - s2[i];
}
