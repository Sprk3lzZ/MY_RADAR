/*
** EPITECH PROJECT, 2023
** radar_event.c
** File description:
** radar_event.c
*/

#include "radar.h"
#include <SFML/Window/Event.h>

static void on_key_pressed(radar_t *radar, sfEvent *event)
{
    if (event->key.code == sfKeyEscape)
        sfRenderWindow_close(radar->window);
    if (event->key.code == sfKeyL)
        radar->show_hitboxes = !radar->show_hitboxes;
    if (event->key.code == sfKeyS)
        radar->show_sprites = !radar->show_sprites;
}

void radar_event(radar_t *radar, sfEvent *event)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(radar->window);
    if (event->type == sfEvtKeyPressed)
        on_key_pressed(radar, event);
}
