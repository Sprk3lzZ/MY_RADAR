/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** my.h
*/

#pragma once

int my_strcmp(char const *s1, char const *s2);
char *my_strndup(char const *string, unsigned long n);
char **my_split(char const *string);
unsigned long my_split_length(char **array);
void my_free_split(char **array);
char *number_to_string(int nb);

int is_number(char const *string);
unsigned int my_getnbr(char const *string);
