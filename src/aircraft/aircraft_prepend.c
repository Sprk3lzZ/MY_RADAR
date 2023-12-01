/*
** EPITECH PROJECT, 2023
** aircraft_prepend.c
** File description:
** aircraft_prepend.c
*/

#include "aircraft.h"

#include <stddef.h>

void aircraft_prepend(aircraft_t **list, aircraft_t *aircraft)
{
    if (*list != NULL)
        aircraft->next = *list;
    *list = aircraft;
}
