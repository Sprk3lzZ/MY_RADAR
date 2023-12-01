/*
** EPITECH PROJECT, 2023
** radar_load_resources.c
** File description:
** radar_load_resources.c
*/

#include "radar.h"

static sfTexture *load_texture(radar_t *radar, char *path)
{
    sfTexture *texture = sfTexture_createFromFile(path, NULL);

    if (!texture)
        radar->status = 84;
    return texture;
}

void radar_load_resources(radar_t *radar)
{
    radar->background_texture = load_texture(radar, "res/background.png");
    radar->aircraft_texture = load_texture(radar, "res/aircraft.png");
    radar->tower_texture = load_texture(radar, "res/tower.png");
}
