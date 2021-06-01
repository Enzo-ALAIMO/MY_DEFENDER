/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** new_wave.c
*/

#include <stdbool.h>
#include "my_defender.h"
#include "scene.h"
#include "enemy.h"
#include "interface.h"
#include "free.h"
#include "util.h"
#include "map.h"

static bool check_new_wave(scene_t scene)
{
    for (int i = 0; i < scene.in_game->nb_enemies; i++)
        if (scene.in_game->arr_enemies[i].health > 0
            && scene.in_game->arr_enemies[i].is_spawned)
            return (false);
    if (scene.in_game->spawner.nb_enemies_spawned
        != scene.in_game->spawner.nb_enemies_to_spawn)
        return (false);
    return (true);
}

static void reset_enemy(scene_t scene)
{
    scene.in_game->arr_enemies = malloc(sizeof(*scene.in_game->arr_enemies)
                            * scene.in_game->nb_enemies);
    for (int i = 0; i < scene.in_game->nb_enemies; i++) {
        scene.in_game->arr_enemies[i] = enemy_init();
        scene.in_game->arr_enemies[i].path = scene.in_game->spawner.path;
        scene.in_game->arr_enemies[i].nb_waypoint = get_size_path(scene.map);
        for (int i = 0; i < scene.in_game->spawner.nb_enemies_to_spawn; i++)
            scene.in_game->arr_enemies[i].health += 1;
        sfSprite_setPosition(scene.in_game->arr_enemies[i].sprite,
        (sfVector2f){scene.in_game->spawner.path[0].x * 96,
        scene.in_game->spawner.path[0].y * 96});
    }
}

void new_wave(scene_t scene)
{
    if (!check_new_wave(scene))
        return;
    free_enemy(scene.in_game);
    scene.in_game->spawner.nb_enemies_spawned = 0;
    scene.in_game->spawner.nb_enemies_to_spawn++;
    scene.in_game->nb_enemies++;
    scene.in_game->nb_waves++;
    update_text_string(scene.arr_texts[TXT_WAVES],
        nb_to_string(scene.in_game->nb_waves));
    reset_enemy(scene);
}