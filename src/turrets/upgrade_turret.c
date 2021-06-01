/*
** EPITECH PROJECT, 2020
** Projects
** File description:
** upgrade_turret.c
*/

#include "my_defender.h"
#include "turret.h"

static turret_t up_tier1(int type)
{
    if (type == 1)
        return (medium_1());
    if (type == 2)
        return (heavy_1());
    if (type == 3)
        return (sniper_1());
    return ((turret_t){0});
}

static turret_t up_tier2(int type)
{
    if (type == 1)
        return (medium_2());
    if (type == 2)
        return (heavy_2());
    if (type == 3)
        return (sniper_2());
    return ((turret_t){0});
}

static turret_t up_tier3(int type)
{
    if (type == 1)
        return (medium_3());
    if (type == 2)
        return (heavy_3());
    if (type == 3)
        return (sniper_3());
    return ((turret_t){0});
}

turret_t get_turret(player_t player)
{
    int type = player.turret_select;

    if (type == 4)
        return (freeze());
    if (player.tier == 1)
        return (up_tier1(type));
    if (player.tier == 2)
        return (up_tier2(type));
    if (player.tier == 3)
        return (up_tier3(type));
    return (medium_1());
}