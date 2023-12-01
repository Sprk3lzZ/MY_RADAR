/*
** EPITECH PROJECT, 2023
** radar_draw.c
** File description:
** radar_draw.c
*/

#include "aircraft.h"
#include "radar.h"
#include "my.h"
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderWindow.h>

static void draw_aircrafts(radar_t *radar)
{
    for (aircraft_t *aircraft = radar->aircrafts; aircraft != NULL;
        aircraft = aircraft->next) {
        if (aircraft->status == AIRCRAFT_DESTROYED
            || aircraft->status == AIRCRAFT_WAITING)
            continue;
        sfSprite_setPosition(radar->aircraft_sprite,
            (sfVector2f){aircraft->position.x - 10, aircraft->position.y - 10});
        sfRectangleShape_setPosition(radar->aircraft_hitbox,
            (sfVector2f){aircraft->position.x - 10, aircraft->position.y - 10});
        if (radar->show_sprites)
            sfRenderWindow_drawSprite(radar->window, radar->aircraft_sprite,
                NULL);
        if (radar->show_hitboxes)
            sfRenderWindow_drawRectangleShape(radar->window,
                radar->aircraft_hitbox, NULL);
    }
}

static void draw_towers(radar_t *radar)
{
    for (tower_t *tower = radar->towers; tower != NULL;
        tower = tower->next) {
        sfSprite_setPosition(radar->tower_sprite,
            (sfVector2f){tower->position.x - 32, tower->position.y - 32});
        sfCircleShape_setPosition(radar->tower_radius,
            (sfVector2f){tower->position.x - tower->radius,
                tower->position.y - tower->radius});
        sfCircleShape_setRadius(radar->tower_radius, tower->radius);
        if (radar->show_sprites)
            sfRenderWindow_drawSprite(radar->window, radar->tower_sprite,
                NULL);
        if (radar->show_hitboxes)
            sfRenderWindow_drawCircleShape(radar->window, radar->tower_radius,
                NULL);
    }
}

void radar_draw(radar_t *radar)
{
    sfText_setString(radar->timer_text, number_to_string(radar->timer));
    sfText_setString(radar->timer_text_2, "Time : ");
    sfRenderWindow_drawSprite(radar->window, radar->background_sprite, NULL);
    draw_aircrafts(radar);
    draw_towers(radar);
    sfRenderWindow_drawText(radar->window, radar->timer_text, NULL);
    sfRenderWindow_drawText(radar->window, radar->timer_text_2, NULL);
}
