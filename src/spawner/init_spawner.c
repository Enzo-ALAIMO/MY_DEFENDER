/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** init_spawner.c
*/

#include "my_defender.h"
#include "map.h"

spawner_t spawner_init(scene_t scene, in_game_t *in_game)
{
    spawner_t spawner;

    spawner.path = get_path(scene.map);
    spawner.nb_enemies_to_spawn = in_game->nb_enemies;
    spawner.nb_enemies_spawned = 0;
    spawner.time_between_spawn = 0.7;
    spawner.time = -3;
    for (int i = 0; i < in_game->nb_enemies; i++) {
        in_game->arr_enemies[i].path = spawner.path;
        in_game->arr_enemies[i].nb_waypoint = get_size_path(scene.map);
        sfSprite_setPosition(in_game->arr_enemies[i].sprite,
        (sfVector2f){spawner.path[0].x * 96, spawner.path[0].y * 96});
    }
    return (spawner);
}