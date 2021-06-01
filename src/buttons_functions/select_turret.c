/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** select_turret.c
*/

#include "my_defender.h"

void select_turret(game_t *game, int type)
{
    game->arr_scenes[game->scene_index].in_game->player.turret_select = type;
}