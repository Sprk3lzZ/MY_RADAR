/*
** EPITECH PROJECT, 2023
** tower_destroy.c
** File description:
** tower_destroy.c
*/

#include "tower.h"

#include <stdlib.h>

void tower_destroy(tower_t *tower)
{
    free(tower);
}
