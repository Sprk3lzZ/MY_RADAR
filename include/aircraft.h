/*
** EPITECH PROJECT, 2023
** aircraft.h
** File description:
** aircraft.h
*/

#pragma once

#include <SFML/System/Vector2.h>

#define AIRCRAFT_WAITING 0
#define AIRCRAFT_FLYING 1
#define AIRCRAFT_HIT 2
#define AIRCRAFT_LANDED 3
#define AIRCRAFT_DESTROYED 4

typedef struct aircraft_s aircraft_t;

struct aircraft_s {
    sfVector2f position;
    sfVector2f velocity;
    float distance;
    float delay;
    int status;
    aircraft_t *next;
};

aircraft_t *aircraft_create(sfVector2f position, sfVector2f velocity,
    float distance, float delay);
void aircraft_destroy(aircraft_t *aircraft);

void aircraft_prepend(aircraft_t **list, aircraft_t *aircraft);
int aircraft_collides(aircraft_t *aircraft, aircraft_t *other);
