/*
** EPITECH PROJECT, 2023
** radar_create_objects.c
** File description:
** radar_create_objects.c
*/

#include "radar.h"
#include <SFML/Graphics/CircleShape.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Sprite.h>

void radar_create_objects(radar_t *radar)
{
    radar->background_sprite = sfSprite_create();
    sfSprite_setTexture(radar->background_sprite, radar->background_texture,
        sfTrue);
    radar->aircraft_sprite = sfSprite_create();
    sfSprite_setTexture(radar->aircraft_sprite, radar->aircraft_texture,
        sfTrue);
    radar->aircraft_hitbox = sfRectangleShape_create();
    sfRectangleShape_setSize(radar->aircraft_hitbox, (sfVector2f){20, 20});
    sfRectangleShape_setFillColor(radar->aircraft_hitbox, sfTransparent);
    sfRectangleShape_setOutlineThickness(radar->aircraft_hitbox, 1);
    sfRectangleShape_setOutlineColor(radar->aircraft_hitbox, sfRed);
    radar->tower_sprite = sfSprite_create();
    sfSprite_setTexture(radar->tower_sprite, radar->tower_texture, sfTrue);
    radar->tower_radius = sfCircleShape_create();
    sfCircleShape_setFillColor(radar->tower_radius, sfTransparent);
    sfCircleShape_setOutlineColor(radar->tower_radius, sfGreen);
    sfCircleShape_setOutlineThickness(radar->tower_radius, 1.0f);
    sfCircleShape_setPointCount(radar->tower_radius, 100);
}
