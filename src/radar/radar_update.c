/*
** EPITECH PROJECT, 2023
** radar_update.c
** File description:
** radar_update.c
*/

#include "aircraft.h"
#include "radar.h"
#include "my.h"

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <math.h>
#include <stdio.h>

static void update_waiting_aircrafts(radar_t *radar, float dt)
{
    for (aircraft_t *aircraft = radar->aircrafts; aircraft != NULL;
        aircraft = aircraft->next) {
        if (aircraft->status != AIRCRAFT_WAITING)
            continue;
        aircraft->delay -= dt;
        if (aircraft->delay <= 0)
            aircraft->status = AIRCRAFT_FLYING;
    }
}

static void update_flying_aircrafts(radar_t *radar, float dt)
{
    sfVector2f movement;
    float distance;

    for (aircraft_t *aircraft = radar->aircrafts; aircraft != NULL;
        aircraft = aircraft->next) {
        if (aircraft->status == AIRCRAFT_WAITING
            || aircraft->status == AIRCRAFT_DESTROYED)
            continue;
        movement.x = aircraft->velocity.x * dt;
        movement.y = aircraft->velocity.y * dt;
        aircraft->position.x += movement.x;
        aircraft->position.y += movement.y;
        distance = sqrt(movement.x * movement.x + movement.y * movement.y);
        aircraft->distance -= distance;
        if (aircraft->distance <= 0)
            aircraft->status = AIRCRAFT_LANDED;
    }
}

static void update_aircrafts_status(radar_t *radar)
{
    int close = 1;

    for (aircraft_t *aircraft = radar->aircrafts; aircraft != NULL;
        aircraft = aircraft->next) {
        if (aircraft->status != AIRCRAFT_DESTROYED)
            close = 0;
        if (aircraft->status == AIRCRAFT_LANDED
            || aircraft->status == AIRCRAFT_HIT)
            aircraft->status = AIRCRAFT_DESTROYED;
    }
    if (close)
        sfRenderWindow_close(radar->window);
}

void radar_update(radar_t *radar, float dt)
{
    radar->timer += dt;
    update_waiting_aircrafts(radar, dt);
    update_flying_aircrafts(radar, dt);
    radar_detect_collisions(radar);
    update_aircrafts_status(radar);
}
