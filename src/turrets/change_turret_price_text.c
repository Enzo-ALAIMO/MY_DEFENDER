/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** change_turret_price_text.c
*/

#include "my_defender.h"
#include "player.h"
#include "turret.h"
#include "scene.h"
#include "util.h"
#include "interface.h"

void change_turret_price_text(game_t *game)
{
    scene_t scene = game->arr_scenes[game->scene_index];

    if (scene.in_game->player.tier == 2) {
        update_text_string(scene.arr_texts[TXT_T_ONE],
            nb_to_string(medium_2().price));
        update_text_string(scene.arr_texts[TXT_T_TWO],
            nb_to_string(heavy_2().price));
        update_text_string(scene.arr_texts[TXT_T_THREE],
            nb_to_string(sniper_2().price));
    } else if (scene.in_game->player.tier == 3) {
        update_text_string(scene.arr_texts[TXT_T_ONE],
            nb_to_string(medium_3().price));
        update_text_string(scene.arr_texts[TXT_T_TWO],
            nb_to_string(heavy_3().price));
        update_text_string(scene.arr_texts[TXT_T_THREE],
            nb_to_string(sniper_3().price));
    }
}