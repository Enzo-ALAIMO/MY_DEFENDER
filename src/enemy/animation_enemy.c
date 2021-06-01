/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** animation_enemy.c
*/

#include "my_defender.h"

void play_animation_enemy(in_game_t *in_game, int i, sfTime dt)
{
    sfSprite_setTextureRect(in_game->arr_enemies[i].sprite,
        in_game->arr_enemies[i].rect);
    in_game->arr_enemies[i].time += sfTime_asSeconds(dt);
    if (in_game->arr_enemies[i].time
        > in_game->arr_enemies[i].time_between_animation) {
        in_game->arr_enemies[i].time = 0;
        if (in_game->arr_enemies[i].rect.left
            + in_game->arr_enemies[i].rect.width >= 960)
            in_game->arr_enemies[i].rect.left = 0;
        else
            in_game->arr_enemies[i].rect.left
                += in_game->arr_enemies[i].rect.width;
    }
}