/*
** EPITECH PROJECT, 2023
** radar_create.c
** File description:
** radar_create.c
*/

#include "radar.h"

#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Window/Window.h>
#include <stdlib.h>

void radar_create_text(radar_t *radar)
{
    radar->timer = 0;
    radar->timer_text = sfText_create();
    radar->timer_text_2 = sfText_create();
    radar->timer_font = sfFont_createFromFile("res/Fruit Days.ttf");
    sfText_setFont(radar->timer_text, radar->timer_font);
    sfText_setCharacterSize(radar->timer_text, 50);
    sfText_setPosition(radar->timer_text, (sfVector2f){1800, 10});
    sfText_setFont(radar->timer_text_2, radar->timer_font);
    sfText_setCharacterSize(radar->timer_text_2, 50);
    sfText_setPosition(radar->timer_text_2, (sfVector2f){1650, 10});
    sfText_setColor(radar->timer_text, sfBlack);
    sfText_setColor(radar->timer_text_2, sfBlack);
}

void radar_create(radar_t *radar, int argc, char **argv, char **env)
{
    radar->status = 0;
    radar->aircrafts = NULL;
    radar->towers = NULL;
    radar->aircraft_sprite = NULL;
    radar->aircraft_texture = NULL;
    radar->background_sprite = NULL;
    radar->background_texture = NULL;
    radar->tower_sprite = NULL;
    radar->tower_texture = NULL;
    radar->tower_radius = NULL;
    radar->window = NULL;
    radar->show_sprites = 1;
    radar->aircraft_hitbox = NULL;
    radar->show_hitboxes = 0;
    radar->fps = 0;
    radar_create_text(radar);
    radar_parse_arguments(radar, argc, argv, env);
}
