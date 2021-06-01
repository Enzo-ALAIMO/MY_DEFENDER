/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** damage_enemy.c
*/

#include "my_defender.h"
#include "scene.h"
#include "util.h"
#include "interface.h"

void enemy_damage_player(scene_t scene, in_game_t *in_game, int i)
{
    enemy_t enemy = in_game->arr_enemies[i];
    sfVector2f enemy_pos = sfSprite_getPosition(enemy.sprite);

    if (roundf(enemy_pos.y) == enemy.path[enemy.nb_waypoint - 1].y * 96
        && roundf(enemy_pos.x) == enemy.path[enemy.nb_waypoint - 1].x * 96) {
        in_game->player.heal--;
        update_text_string(scene.arr_texts[TXT_LIFES],
                nb_to_string(in_game->player.heal));
        enemy.is_spawned = false;
    }
    in_game->arr_enemies[i] = enemy;
}