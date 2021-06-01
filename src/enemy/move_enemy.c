/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** move_enemy.c
*/

#include "my_defender.h"
#include "math.h"

static void move_up_down(sfTime dt, in_game_t *in_game, int i, int dir)
{
    enemy_t enemy = in_game->arr_enemies[i];
    sfVector2f enemy_pos = sfSprite_getPosition(enemy.sprite);

    enemy_pos.y += dir * (enemy.speed * sfTime_asSeconds(dt));
    sfSprite_setPosition(enemy.sprite, enemy_pos);
    in_game->arr_enemies[i] = enemy;
}

void move_enemy(in_game_t *in_game, int i, sfTime dt)
{
    enemy_t enemy = in_game->arr_enemies[i];
    sfVector2f enemy_pos = sfSprite_getPosition(enemy.sprite);

    if (roundf(enemy_pos.y) < enemy.path[enemy.current_waypoint].y * 96) {
        move_up_down(dt, in_game, i, 1);
        return;
    } else if (roundf(enemy_pos.y) >
            enemy.path[enemy.current_waypoint].y * 96) {
        move_up_down(dt, in_game, i, -1);
        return;
    }
    if (roundf(enemy_pos.x) < enemy.path[enemy.current_waypoint].x * 96)
        enemy_pos.x += enemy.speed * sfTime_asSeconds(dt);
    else if (roundf(enemy_pos.x) > enemy.path[enemy.current_waypoint].x * 96)
        enemy_pos.x -= enemy.speed * sfTime_asSeconds(dt);
    else
        if (enemy.current_waypoint < enemy.nb_waypoint - 1)
            enemy.current_waypoint++;
    sfSprite_setPosition(enemy.sprite, enemy_pos);
    in_game->arr_enemies[i] = enemy;
}