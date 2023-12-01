/*
** EPITECH PROJECT, 2023
** aircraft_collides.c
** File description:
** aircraft_collides.c
*/

#include "aircraft.h"

int aircraft_collides(aircraft_t *aircraft, aircraft_t *other)
{
    return other->position.x + 20 > aircraft->position.x
        && other->position.y + 20 > aircraft->position.y
        && aircraft->position.x + 20 > other->position.x
        && aircraft->position.y + 20 > other->position.y;
}
