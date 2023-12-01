/*
** EPITECH PROJECT, 2023
** radar_destroy.c
** File description:
** radar_destroy.c
*/

#include "radar.h"
#include "tower.h"

#include <SFML/Graphics.h>
#include <SFML/Graphics/Text.h>
#include <stdlib.h>

void destroy_entities(radar_t *radar)
{
    aircraft_t *next_aircraft;
    tower_t *next_tower;

    for (aircraft_t *aircraft = radar->aircrafts; aircraft != NULL;
        aircraft = next_aircraft) {
        next_aircraft = aircraft->next;
        aircraft_destroy(aircraft);
    }
    for (tower_t *tower = radar->towers; tower != NULL; tower = next_tower) {
        next_tower = tower->next;
        tower_destroy(tower);
    }
}

void radar_destroy(radar_t *radar)
{
    destroy_entities(radar);
    sfSprite_destroy(radar->background_sprite);
    sfSprite_destroy(radar->aircraft_sprite);
    sfSprite_destroy(radar->tower_sprite);
    sfRectangleShape_destroy(radar->aircraft_hitbox);
    sfCircleShape_destroy(radar->tower_radius);
    sfTexture_destroy(radar->background_texture);
    sfTexture_destroy(radar->aircraft_texture);
    sfTexture_destroy(radar->tower_texture);
    sfRenderWindow_destroy(radar->window);
    sfFont_destroy(radar->timer_font);
    sfText_destroy(radar->timer_text);
    sfText_destroy(radar->timer_text_2);
}
