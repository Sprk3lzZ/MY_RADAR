/*
** EPITECH PROJECT, 2023
** radar_detect_collisions.c
** File description:
** radar_detect_collisions.c
*/

#include "aircraft.h"
#include "radar.h"
#include "tower.h"

static int is_safe(radar_t *radar, aircraft_t *aircraft)
{
    for (tower_t *tower = radar->towers; tower != NULL; tower = tower->next)
        if (tower_collides(tower, aircraft))
            return 1;
    return 0;
}

static void detect_collision(radar_t *radar, aircraft_t *aircraft,
    aircraft_t *other)
{
    if (aircraft == other
        || aircraft->status == AIRCRAFT_WAITING
        || aircraft->status == AIRCRAFT_DESTROYED
        || other->status == AIRCRAFT_WAITING
        || other->status == AIRCRAFT_DESTROYED)
        return;
    if (aircraft_collides(aircraft, other)) {
        if (!is_safe(radar, aircraft))
            aircraft->status = AIRCRAFT_HIT;
        if (!is_safe(radar, other))
            other->status = AIRCRAFT_HIT;
    }
}

void radar_detect_collisions(radar_t *radar)
{
    for (aircraft_t *aircraft = radar->aircrafts; aircraft != NULL;
        aircraft = aircraft->next)
        for (aircraft_t *other = radar->aircrafts; other != NULL;
            other = other->next)
            detect_collision(radar, aircraft, other);
}
