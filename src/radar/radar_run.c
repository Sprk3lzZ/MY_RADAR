/*
** EPITECH PROJECT, 2023
** radar_run.c
** File description:
** radar_run.c
*/

#include "radar.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/System/Clock.h>

static void radar_loop(radar_t *radar)
{
    sfClock *clock = sfClock_create();
    sfEvent event;

    while (sfRenderWindow_isOpen(radar->window)) {
        while (sfRenderWindow_pollEvent(radar->window, &event))
            radar_event(radar, &event);
        radar_update(radar, sfTime_asSeconds(sfClock_restart(clock)));
        sfRenderWindow_clear(radar->window, sfBlack);
        radar_draw(radar);
        sfRenderWindow_display(radar->window);
    }
    sfClock_destroy(clock);
}

void radar_run(radar_t *radar)
{
    if (radar->status == STATUS_ERROR || radar->status == STATUS_HELP)
        return;
    radar_loop(radar);
}
