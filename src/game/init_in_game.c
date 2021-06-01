/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** init_in_game.c
*/

#include <stdlib.h>
#include "my_defender.h"
#include "enemy.h"
#include "spawner.h"
#include "player.h"
#include "map.h"
#include "turret.h"
#include "free.h"

static sfSprite *create_sprite(char *path)
{
    sfTexture *texture = sfTexture_createFromFile(path, NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfFalse);
    return (sprite);
}

map_t *map_init(char *map_path)
{
    map_t *map = malloc(sizeof(map_t));
    map->filepath = map_path;
    map->map_str = init_map(map->filepath, map);
    return (map);
}

in_game_t *in_game_init(scene_t scene, in_game_t *in_game)
{
    if (in_game->hud == NULL)
        in_game->hud = create_sprite("./assets/in_game/hud.png");
    if (in_game->arr_enemies != NULL)
        free_enemy(in_game);
    in_game->arr_enemies = malloc(sizeof(*in_game->arr_enemies)
                            * in_game->nb_enemies);
    for (int i = 0; i < in_game->nb_enemies; i++)
        in_game->arr_enemies[i] = enemy_init();
    in_game->spawner = spawner_init(scene, in_game);
    if (in_game->arr_turret != NULL)
        free_turret(in_game);
    in_game->arr_turret = malloc(sizeof(turret_t) * in_game->nb_turrets);
    for (int i = 0; i < in_game->nb_turrets; i++)
        in_game->arr_turret[i].index = -1;
    in_game->nb_turrets = get_nb_turrets(scene.map->str_map);
    in_game->player = init_player();
    return (in_game);
}