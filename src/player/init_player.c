/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** init_player.c
*/

#include "my_defender.h"

player_t init_player(void)
{
    return ((player_t) {
        .gold = 100,
        .heal = 5,
        .turret_select = 0,
        .tier = 1,
    });
}