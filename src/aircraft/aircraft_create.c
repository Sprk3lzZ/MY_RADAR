/*
** EPITECH PROJECT, 2023
** aircraft_create.c
** File description:
** aircraft_create.c
*/

#include "aircraft.h"

#include <stdlib.h>

aircraft_t *aircraft_create(sfVector2f position, sfVector2f velocity,
    float distance, float delay)
{
    aircraft_t *aircraft = malloc(sizeof(aircraft_t));

    aircraft->position = position;
    aircraft->velocity = velocity;
    aircraft->distance = distance;
    aircraft->delay = delay;
    aircraft->status = AIRCRAFT_WAITING;
    aircraft->next = NULL;
    return aircraft;
}
