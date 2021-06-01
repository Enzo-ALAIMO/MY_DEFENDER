/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** handle_border.c
*/

#include "my_defender.h"
#include "map.h"
#include <SFML/Graphics.h>

sfVector2i check_border(path_t *path, map_t *map, sfVector2i v, sfVector2i h)
{
    if (!is_used(path, (sfVector2i){path->pos.x, path->pos.y + v.x})
        && v.x != 0 && map->map_str[path->pos.y + v.x][path->pos.x] == ' ') {
        path->pos.y += v.x;
        return ((sfVector2i){path->pos.x, path->pos.y});
    }
    if (!is_used(path, (sfVector2i){path->pos.x, path->pos.y + v.y})
        && v.y != 0 && map->map_str[path->pos.y + v.y][path->pos.x] == ' ') {
        path->pos.y += v.y;
        return ((sfVector2i){path->pos.x, path->pos.y});
    }
    if (!is_used(path, (sfVector2i){path->pos.x + h.x, path->pos.y})
        && h.x != 0 && map->map_str[path->pos.y][path->pos.x + h.x] == ' ') {
        path->pos.x += h.x;
        return ((sfVector2i){path->pos.x, path->pos.y});
    }
    if (!is_used(path, (sfVector2i){path->pos.x + h.y, path->pos.y})
        && h.y != 0 && map->map_str[path->pos.y][path->pos.x + h.y] == ' ') {
        path->pos.x += h.y;
        return ((sfVector2i){path->pos.x, path->pos.y});
    }
    return ((sfVector2i){0, 0});
}

sfVector2i *handle_border(path_t *path, map_t *map)
{
    if (path->pos.y == 0 && path->pos.x > 0 && path->pos.x < map->x - 1)
        path->path[path->index] = check_border(path, map,
            (sfVector2i){1, 0}, (sfVector2i){1, -1});
    if (path->pos.y == map->y - 1
        && path->pos.x > 0 && path->pos.x < map->x - 1)
        path->path[path->index] = check_border(path, map,
            (sfVector2i){-1, 0}, (sfVector2i){1, -1});
    if (path->pos.y > 0 && path->pos.y < map->y - 1 && path->pos.x == 0)
        path->path[path->index] = check_border(path, map,
            (sfVector2i){1, -1}, (sfVector2i){1, 0});
    if (path->pos.y > 0 && path->pos.y < map->y - 1
        && path->pos.x == map->x - 1)
        path->path[path->index] = check_border(path, map,
            (sfVector2i){1, -1}, (sfVector2i){-1, 0});
    path->pos_used[path->index] = (sfVector2i){path->pos.x, path->pos.y};
    return (path->path);
}