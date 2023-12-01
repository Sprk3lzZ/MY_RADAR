/*
** EPITECH PROJECT, 2023
** radar.h
** File description:
** radar.h
*/

#pragma once

#include <SFML/Graphics.h>

#include "aircraft.h"
#include "tower.h"

#define STATUS_OK 0
#define STATUS_HELP 1
#define STATUS_ERROR 2

typedef struct {
    sfRenderWindow *window;

    sfTexture *background_texture;
    sfSprite *background_sprite;

    sfSprite *aircraft_sprite;
    sfTexture *aircraft_texture;
    sfRectangleShape *aircraft_hitbox;

    sfTexture *tower_texture;
    sfSprite *tower_sprite;
    sfCircleShape *tower_radius;

    aircraft_t *aircrafts;
    tower_t *towers;

    int status;
    int show_sprites;
    int show_hitboxes;

    float timer;
    int fps;
    sfText *timer_text;
    sfText *timer_text_2;
    sfText *timer_text_3;
    sfFont *timer_font;
} radar_t;

//RADAR
int my_radar(int argc, char **argv, char **env);

void radar_create(radar_t *radar, int argc, char **argv, char **env);
void radar_destroy(radar_t *radar);

void radar_parse_arguments(radar_t *radar, int argc, char **argv, char **env);
void radar_load_resources(radar_t *radar);
void radar_load_script(radar_t *radar, char *path);
void radar_create_objects(radar_t *radar);

void radar_help(char *program);
void radar_run(radar_t *radar);

void radar_event(radar_t *radar, sfEvent *event);
void radar_update(radar_t *radar, float dt);
void radar_draw(radar_t *radar);

void radar_detect_collisions(radar_t *radar);
