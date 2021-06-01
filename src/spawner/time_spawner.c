/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** time_spawner.c
*/

#include "my_defender.h"
#include "spawner.h"

void update_spawner_timer(scene_t scene, sfTime dt)
{
    scene.in_game->spawner.time += sfTime_asSeconds(dt);
    if (scene.in_game->spawner.time
        >= scene.in_game->spawner.time_between_spawn
        && scene.in_game->spawner.nb_enemies_spawned
        < scene.in_game->spawner.nb_enemies_to_spawn) {
        scene.in_game->arr_enemies[scene.in_game->spawner.nb_enemies_spawned++]
            .is_spawned = true;
        scene.in_game->spawner.time = 0;
    }
    new_wave(scene);
}