/*
** EPITECH PROJECT, 2020
** Projects
** File description:
** map.c
*/

#include "my_defender.h"
#include "map.h"
#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void copy_buff(char *buff, map_t *map)
{
    map->str_map = malloc(sizeof(char) * 1000);

    memset(map->str_map, '\0', 1000);
    if (map->str_map == NULL)
        return;
    for (int i = 0; buff[i] != '\0'; i++)
        map->str_map[i] = buff[i];
}

int get_x(char *map)
{
    int i;

    for (i = 0; map[i] != '\n'; i++);
    return (i);
}

int get_y(char *map)
{
    int cpt = 0;

    for (int i = 0; map[i] != '\0'; i++)
        if (map[i] == '\n')
            cpt++;
    return (cpt + 1);
}

char **init_map(char *filepath, map_t *map)
{
    int x = 0;
    int y = 0;
    FILE *file = fopen(filepath, "r");
    char *buff = malloc(sizeof(char) * 1000 + 1);

    if (buff == NULL)
        return (NULL);
    memset(buff, '\0', 1000);
    if (file == NULL)
        return (NULL);
    fread(buff, sizeof(char), 1000, file);
    buff[1000] = '\0';
    copy_buff(buff, map);
    y = get_y(map->str_map);
    x = get_x(map->str_map);
    map->map_str = map_2d_array(map->str_map, y, x);
    fclose(file);
    return (map->map_str);
}