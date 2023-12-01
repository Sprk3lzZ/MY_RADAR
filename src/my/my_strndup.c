/*
** EPITECH PROJECT, 2023
** my_strndup.c
** File description:
** my_strndup.c
*/

#include "my.h"

#include <stdlib.h>

char *my_strndup(char const *string, unsigned long n)
{
    char *copy = malloc((n + 1) * sizeof(char));

    for (unsigned long i = 0; i < n; i++)
        copy[i] = string[i];
    copy[n] = '\0';
    return copy;
}
