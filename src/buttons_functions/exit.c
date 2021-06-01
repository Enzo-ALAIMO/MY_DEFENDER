/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** exit.c
*/

#include "my_defender.h"

void exit_game(game_t *game)
{
    sfRenderWindow_close(game->window);
}