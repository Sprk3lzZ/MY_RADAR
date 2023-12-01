/*
** EPITECH PROJECT, 2023
** radar_load_script.c
** File description:
** radar_load_script.c
*/

#include "aircraft.h"
#include "radar.h"
#include "my.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static int parse_aircraft(radar_t *radar, char **words, unsigned long count)
{
    sfVector2f position;
    sfVector2f terminus;
    sfVector2f velocity;
    float distance;

    if (count != 7)
        return 84;
    if (!is_number(words[1]) || !is_number(words[2]) || !is_number(words[3])
        || !is_number(words[4]) || !is_number(words[5]) || !is_number(words[6]))
        return 84;
    position = (sfVector2f) {my_getnbr(words[1]), my_getnbr(words[2])};
    terminus = (sfVector2f) {my_getnbr(words[3]), my_getnbr(words[4])};
    velocity = (sfVector2f) {terminus.x - position.x, terminus.y - position.y};
    distance = sqrt(velocity.x * velocity.x + velocity.y * velocity.y);
    velocity.x = velocity.x / distance * my_getnbr(words[5]);
    velocity.y = velocity.y / distance * my_getnbr(words[5]);
    aircraft_prepend(&radar->aircrafts, aircraft_create(position, velocity,
        distance, my_getnbr(words[6])));
    return 0;
}

static int parse_tower(radar_t *radar, char **words, unsigned long count)
{
    sfVector2f position;

    if (count != 4)
        return 84;
    if (!is_number(words[1]) || !is_number(words[2]))
        return 84;
    position = (sfVector2f) {my_getnbr(words[1]), my_getnbr(words[2])};
    tower_prepend(&radar->towers, tower_create(position,
        my_getnbr(words[3])));
    return 0;
}

static int parse_line(radar_t *radar, char **words, unsigned long count)
{
    if (count == 0)
        return 84;
    if (my_strcmp(words[0], "A") == 0)
        return parse_aircraft(radar, words, count);
    if (my_strcmp(words[0], "T") == 0)
        return parse_tower(radar, words, count);
    return 84;
}

void radar_load_script(radar_t *radar, char *path)
{
    FILE *file = fopen(path, "r");
    char *line = NULL;
    char **words;
    size_t len = 0;
    int result = 0;
    if (file == NULL) {
        radar->status = STATUS_ERROR;
        return;
    }
    while (getline(&line, &len, file) != -1) {
        words = my_split(line);
        result = parse_line(radar, words, my_split_length(words));
        my_free_split(words);
        if (result == 84) {
            radar->status = STATUS_ERROR;
            break;
        }
    }
    fclose(file);
    free(line);
}
