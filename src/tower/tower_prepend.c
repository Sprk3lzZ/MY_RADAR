/*
** EPITECH PROJECT, 2023
** tower_prepend.c
** File description:
** tower_prepend.c
*/

#include "tower.h"

#include <stddef.h>

void tower_prepend(tower_t **list, tower_t *tower)
{
    if (*list != NULL)
        tower->next = *list;
    *list = tower;
}
