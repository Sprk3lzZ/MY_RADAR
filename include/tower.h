/*
** EPITECH PROJECT, 2023
** tower.h
** File description:
** tower.h
*/

#pragma once

#include "aircraft.h"
#include <SFML/System/Vector2.h>

typedef struct tower_s tower_t;

struct tower_s {
    sfVector2f position;
    float radius;
    tower_t *next;
};

tower_t *tower_create(sfVector2f position, float radius);
void tower_destroy(tower_t *tower);

void tower_prepend(tower_t **list, tower_t *tower);
int tower_collides(tower_t *tower, aircraft_t *aircraft);
