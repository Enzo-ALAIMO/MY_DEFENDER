/*
** EPITECH PROJECT, 2020
** Projects
** File description:
** get_turret.c
*/

#include "my_defender.h"
#include "player.h"
#include "turret.h"

static int price_tier1(int type)
{
    if (type == 1)
        return (medium_1().price);
    if (type == 2)
        return (heavy_1().price);
    if (type == 3)
        return (sniper_1().price);
    return (0);
}

static int price_tier2(int type)
{
    if (type == 1)
        return (medium_2().price);
    if (type == 2)
        return (heavy_2().price);
    if (type == 3)
        return (sniper_2().price);
    return (0);
}

static int price_tier3(int type)
{
    if (type == 1)
        return (medium_3().price);
    if (type == 2)
        return (heavy_3().price);
    if (type == 3)
        return (sniper_3().price);
    return (0);
}

int get_turret_price(game_t *game)
{
    int type =
        game->arr_scenes[game->scene_index].in_game->player.turret_select;

    if (type == 4)
        return (freeze().price);
    if (game->arr_scenes[game->scene_index].in_game->player.tier == 1)
        return (price_tier1(type));
    if (game->arr_scenes[game->scene_index].in_game->player.tier == 2)
        return (price_tier2(type));
    if (game->arr_scenes[game->scene_index].in_game->player.tier == 3)
        return (price_tier3(type));
    return (0);
}