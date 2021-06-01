/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** get_path.c
*/

#include "my_defender.h"
#include "map.h"
#include <SFML/Graphics.h>
#include <stdbool.h>
#include <stdlib.h>

int get_size_path(map_t *map)
{
    int size_path = 0;

    for (int i = 0; i < get_y(map->str_map); i++)
        for (int j = 0; j < get_x(map->str_map); j++)
            if (map->map_str[i][j] == ' ')
                size_path++;
    return (size_path);
}

static sfVector2i get_spawner_pos(map_t *map)
{
    sfVector2i pos = {0, 0};

    for (int i = 0; i < get_y(map->str_map); i++)
        for (int j = 0; j < get_x(map->str_map); j++)
            if (map->map_str[i][j] == 'S') {
                pos = (sfVector2i){j, i};
                break;
            }
    return (pos);
}

bool is_used(path_t *path, sfVector2i pos)
{
    for (int i = 0; i < path->index; i++)
        if (path->pos_used[i].x == pos.x && path->pos_used[i].y == pos.y)
            return (true);
    return (false);
}

sfVector2i *get_path(map_t *map)
{
    path_t *path = malloc(sizeof(path_t));

    path->size_path = get_size_path(map);
    path->path = malloc(sizeof(*path) * path->size_path);
    path->pos_used = malloc(sizeof(*path->pos_used) * path->size_path);
    path->pos = get_spawner_pos(map);
    for (map->y = 0; map->y < get_y(map->str_map); map->y++);
    for (map->x = 0; map->x < get_x(map->str_map); map->x++);
    for (path->index = 0; path->index < path->size_path; path->index++) {
        path->path = handle_corner(path, map);
        path->path = handle_border(path, map);
        path->path = handle_inside(path, map);
    }
    return (path->path);
}