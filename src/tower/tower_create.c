/*
** EPITECH PROJECT, 2023
** tower_create.c
** File description:
** tower_create.c
*/

#include "tower.h"

#include <stdlib.h>

tower_t *tower_create(sfVector2f position, float radius)
{
    tower_t *tower = malloc(sizeof(tower_t));

    tower->position = position;
    tower->radius = radius;
    tower->next = NULL;
    return tower;
}
