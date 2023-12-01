/*
** EPITECH PROJECT, 2023
** my_radar.c
** File description:
** my_radar.c
*/

#include "radar.h"

int my_radar(int argc, char **argv, char **env)
{
    radar_t radar;

    radar_create(&radar, argc, argv, env);
    radar_run(&radar);
    radar_destroy(&radar);
    return radar.status == STATUS_ERROR ? 84 : 0;
}
