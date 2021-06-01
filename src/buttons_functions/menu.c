/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** menu.c
*/

#include "my_defender.h"

void return_to_menu(game_t *game)
{
    game->arr_scenes[game->scene_index].change = true;
}