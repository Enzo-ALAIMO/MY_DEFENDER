/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** get_turret_sprite_index.c
*/

#include "my_defender.h"
#include "turret.h"

static int index_tier1(int type)
{
    if (type == 1)
        return (medium_1().index);
    if (type == 2)
        return (heavy_1().index);
    if (type == 3)
        return (sniper_1().index);
    return (0);
}

static int index_tier2(int type)
{
    if (type == 1)
        return (medium_2().index);
    if (type == 2)
        return (heavy_2().index);
    if (type == 3)
        return (sniper_2().index);
    return (0);
}

static int index_tier3(int type)
{
    if (type == 1)
        return (medium_3().index);
    if (type == 2)
        return (heavy_3().index);
    if (type == 3)
        return (sniper_3().index);
    return (0);
}

int get_turret_sprite_index(player_t player)
{
    if (player.turret_select == 4)
        return (freeze().index);
    if (player.tier == 1)
        return (index_tier1(player.turret_select));
    if (player.tier == 2)
        return (index_tier2(player.turret_select));
    if (player.tier == 3)
        return (index_tier3(player.turret_select));
    return (0);
}