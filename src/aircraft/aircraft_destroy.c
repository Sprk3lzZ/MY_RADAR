/*
** EPITECH PROJECT, 2023
** aircraft_destroy.c
** File description:
** aircraft_destroy.c
*/

#include "aircraft.h"

#include <stdlib.h>

void aircraft_destroy(aircraft_t *aircraft)
{
    free(aircraft);
}
