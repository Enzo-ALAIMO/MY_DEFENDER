/*
** EPITECH PROJECT, 2020
** Projects
** File description:
** main.c
*/

#include "my_defender.h"
#include "map.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void set_sprites_map(sprites_t *sprites, textures_t *textures)
{
    sfVector2f scale = {0.8, 0.8};
    char *img_path[] = { "./assets/sprite_map/map_decor.png",
                        "./assets/sprite_map/map_spawner.png",
                        "./assets/sprite_map/map_path.png",
                        "./assets/sprite_map/map_base.png",
                        "./assets/sprite_map/map_turret.png" };

    sprites->arr_spr = malloc(sizeof(*sprites->arr_spr) * NB_SPR);
    for (int i = 0; i < NB_SPR; i++)
        sprites->arr_spr[i] = sfSprite_create();
    textures->my_arr_spr = malloc(sizeof(*textures->my_arr_spr) * NB_SPR);
    for (int i = 0; i < NB_SPR; i++)
        textures->my_arr_spr[i] = sfTexture_createFromFile(img_path[i], NULL);
    for (int i = 0; i < NB_SPR; i++)
        sfSprite_setTexture(sprites->arr_spr[i], textures->my_arr_spr[i],
            sfFalse);
    for (int i = 0; i < NB_SPR; i++)
        sfSprite_setScale(sprites->arr_spr[i], scale);
}

void display_map(map_t *map, sprites_t *sprites, sfRenderWindow *window)
{
    map->y = 0;
    map->x = 0;
    for (int i = 0; map->str_map[i]; i++) {
        if (map->str_map[i] == 'X')
            display_decor(map, sprites, window);
        if (map->str_map[i] == 'S')
            display_spawner(map, sprites, window);
        if (map->str_map[i] == 'C')
            display_base(map, sprites, window);
        if (map->str_map[i] == 'O')
            display_turret(map, sprites, window);
        if (map->str_map[i] == 'T')
            display_turret(map, sprites, window);
        if (map->str_map[i] == ' ')
            display_path(map, sprites, window);
        if (map->str_map[i] == '\n') {
            map->y = map->y + 96;
            map->x = 0;
        } else
            map->x = map->x + 96;
    }
}