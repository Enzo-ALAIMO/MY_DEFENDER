/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** pause.c
*/

#include "my_defender.h"

void resume_game(game_t *game)
{
    game->arr_scenes[game->scene_index].pause =
                !game->arr_scenes[game->scene_index].pause;
    sfClock_restart(game->arr_scenes[game->scene_index].clock_dt);
}