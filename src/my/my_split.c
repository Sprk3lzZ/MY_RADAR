/*
** EPITECH PROJECT, 2023
** my_split.c
** File description:
** my_split.c
*/

#include "my.h"

#include <stdlib.h>

static unsigned long get_count(char const *string)
{
    unsigned long count = 0;
    int space = 1;

    for (unsigned long i = 0; string[i] != '\0'; i++) {
        if (string[i] == ' ' || string[i] == '\t' || string[i] == '\n') {
            space = 1;
            continue;
        }
        if (space)
            count++;
        space = 0;
    }
    return count;
}

static char *get_next(char const **string)
{
    char const *word;

    while (**string == ' ' || **string == '\t' || **string == '\n')
        (*string)++;
    word = *string;
    while (**string != ' ' && **string != '\t' && **string != '\n'
        && **string != '\0')
        (*string)++;
    return my_strndup(word, *string - word);
}

char **my_split(char const *string)
{
    unsigned long count = get_count(string);
    char **words = malloc((count + 1) * sizeof(char *));

    for (unsigned long i = 0; i < count; i++)
        words[i] = get_next(&string);
    words[count] = 0;
    return words;
}

unsigned long my_split_length(char **array)
{
    unsigned long length = 0;

    while (array[length])
        length++;
    return length;
}

void my_free_split(char **array)
{
    for (unsigned long i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}
