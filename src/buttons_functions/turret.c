/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** select_turret.c
*/

#include "my_defender.h"
#include "free.h"
#include "turret.h"

static turret_t turret_tier2(int type)
{
    if (type == 1)
        return (medium_2());
    if (type == 2)
        return (heavy_2());
    if (type == 3)
        return (sniper_2());
    return ((turret_t){0});
}

static turret_t turret_tier3(int type)
{
    if (type == 1)
        return (medium_3());
    if (type == 2)
        return (heavy_3());
    if (type == 3)
        return (sniper_3());
    return ((turret_t){0});
}

void upgrade_turret(game_t *game)
{
    scene_t scene = game->arr_scenes[game->scene_index];
    player_t player = scene.in_game->player;
    turret_t get_turret = {0};

    for (int i = 0; i < scene.in_game->nb_turrets; i++) {
        if (scene.in_game->arr_turret[i].index == -1)
            continue;
        if (scene.in_game->arr_turret[i].tier == 1 && player.tier == 2) {
            get_turret = turret_tier2(scene.in_game->arr_turret[i].type);
            get_turret.x = scene.in_game->arr_turret[i].x;
            get_turret.y = scene.in_game->arr_turret[i].y;
            get_turret.fire_rate = 1;
            sfSprite_setOrigin(game->sprites->arr_tur[get_turret.index],
                (sfVector2f){175, 175});
            scene.in_game->arr_turret[i] = get_turret;
            continue;
        }
        if (scene.in_game->arr_turret[i].tier == 2 && player.tier == 3) {
            get_turret = turret_tier3(scene.in_game->arr_turret[i].type);
            get_turret.x = scene.in_game->arr_turret[i].x;
            get_turret.y = scene.in_game->arr_turret[i].y;
            get_turret.fire_rate = 1;
            sfSprite_setOrigin(game->sprites->arr_tur[get_turret.index],
                (sfVector2f){175, 175});
            scene.in_game->arr_turret[i] = get_turret;
        }
    }
}