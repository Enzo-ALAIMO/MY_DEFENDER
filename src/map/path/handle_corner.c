/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** handle_corner.c
*/

#include "my_defender.h"
#include "map.h"
#include <SFML/Graphics.h>

sfVector2i check_corner(path_t *path, map_t *map, sfVector2i pos)
{
    if (!is_used(path, (sfVector2i){path->pos.x, path->pos.y + pos.y})
        && map->map_str[path->pos.y + pos.y][path->pos.x] == ' ') {
        path->pos.y += pos.y;
        return ((sfVector2i){path->pos.x, path->pos.y});
    }
    if (!is_used(path, (sfVector2i){path->pos.x + pos.x, path->pos.y})
        && map->map_str[path->pos.y][path->pos.x + pos.x] == ' ') {
        path->pos.x += pos.x;
        return ((sfVector2i){path->pos.x, path->pos.y});
    }
    return ((sfVector2i){0, 0});
}

sfVector2i *handle_corner(path_t *path, map_t *map)
{
    if (path->pos.y == 0 && path->pos.x == 0)
        path->path[path->index] = check_corner(path, map, (sfVector2i){1, 1});
    if (path->pos.y == 0 && path->pos.x == map->x - 1)
        path->path[path->index] = check_corner(path, map, (sfVector2i){1, -1});
    if (path->pos.y == map->y - 1 && path->pos.x == 0)
        path->path[path->index] = check_corner(path, map, (sfVector2i){-1, 1});
    if (path->pos.y == map->y - 1 && path->pos.x == map->x - 1)
        path->path[path->index] = check_corner(path, map, (sfVector2i){-1, -1});
    path->pos_used[path->index] = (sfVector2i){path->pos.x, path->pos.y};
    return (path->path);
}