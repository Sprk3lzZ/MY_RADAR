/*
** EPITECH PROJECT, 2023
** tower_collides.c
** File description:
** tower_collides.c
*/

#include "tower.h"

static int is_inside(tower_t *tower, sfVector2f position)
{
    return (tower->position.x - position.x) * (tower->position.x - position.x)
        + (tower->position.y - position.y) * (tower->position.y - position.y)
        <= tower->radius * tower->radius;
}

int tower_collides(tower_t *tower, aircraft_t *aircraft)
{
    return is_inside(tower, aircraft->position)
        || is_inside(tower, (sfVector2f){aircraft->position.x + 20,
            aircraft->position.y})
        || is_inside(tower, (sfVector2f){aircraft->position.x,
            aircraft->position.y + 20})
        || is_inside(tower, (sfVector2f){aircraft->position.x + 20,
            aircraft->position.y + 20});
}
