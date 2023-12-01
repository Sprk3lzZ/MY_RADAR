/*
** EPITECH PROJECT, 2023
** radar_parse_arguments.c
** File description:
** radar_parse_arguments.c
*/

#include "radar.h"
#include "my.h"

void radar_parse_arguments(radar_t *radar, int argc, char **argv, char **env)
{
    if (!env[0] || argc != 2) {
        radar->status = STATUS_ERROR;
        return;
    }
    if (my_strcmp(argv[1], "-h") == 0) {
        radar->status = STATUS_HELP;
        radar_help(argv[0]);
        return;
    }
    radar_load_script(radar, argv[1]);
    if (radar->status == STATUS_ERROR)
        return;
    radar->window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32},
        "MyRadar", sfFullscreen, NULL);
    radar_load_resources(radar);
    radar_create_objects(radar);
}
