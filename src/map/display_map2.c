/*
** EPITECH PROJECT, 2020
** Projects
** File description:
** map.c
*/

#include "my_defender.h"

void display_decor(map_t *map, sprites_t *sprites, sfRenderWindow *window)
{
    sfSprite_setPosition(sprites->arr_spr[SPR_DECOR],
    (sfVector2f){map->x, map->y});
    sfRenderWindow_drawSprite(window, sprites->arr_spr[SPR_DECOR], NULL);
}

void display_spawner(map_t *map, sprites_t *sprites, sfRenderWindow *window)
{
    sfSprite_setPosition(sprites->arr_spr[SPR_SPAWNER],
    (sfVector2f){map->x, map->y});
    sfRenderWindow_drawSprite(window, sprites->arr_spr[SPR_SPAWNER], NULL);
}

void display_path(map_t *map, sprites_t *sprites, sfRenderWindow *window)
{
    sfSprite_setPosition(sprites->arr_spr[SPR_PATH],
    (sfVector2f){map->x, map->y});
    sfRenderWindow_drawSprite(window, sprites->arr_spr[SPR_PATH], NULL);
}

void display_base(map_t *map, sprites_t *sprites, sfRenderWindow *window)
{
    sfSprite_setPosition(sprites->arr_spr[SPR_BASE],
    (sfVector2f){map->x, map->y});
    sfRenderWindow_drawSprite(window, sprites->arr_spr[SPR_BASE], NULL);
}

void display_turret(map_t *map, sprites_t *sprites, sfRenderWindow *window)
{
    sfSprite_setPosition(sprites->arr_spr[SPR_TURRET],
    (sfVector2f){map->x, map->y});
    sfRenderWindow_drawSprite(window, sprites->arr_spr[SPR_TURRET], NULL);
}