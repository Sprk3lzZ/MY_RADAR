/*
** EPITECH PROJECT, 2023
** radar_help.c
** File description:
** radar_help.c
*/

#include "radar.h"

#include <unistd.h>

static int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}

static void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}

void radar_help(char *program)
{
    my_putstr("Air traffic simulation panel\n\n");
    my_putstr("USAGE\n");
    my_putstr(program);
    my_putstr(" [OPTIONS] path_to_script\n");
    my_putstr(" path_to_script       The path to script file.\n\n");
    my_putstr("OPTIONS\n");
    my_putstr(" -h                   Print the usage and quit.\n\n");
    my_putstr("USER INTERACTIONS\n");
    my_putstr(" 'L'   key              Enable/disable hitboxes and areas.\n");
    my_putstr(" 'S'   key              Enable/disable sprites.\n");
    my_putstr(" 'ESC' key              Exit the program.\n");
}
