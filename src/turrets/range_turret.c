/*
** EPITECH PROJECT, 2020
** Projects
** File description:
** main.c
*/

#include "my_defender.h"
#include <SFML/Graphics.h>
#include <math.h>
#include <limits.h>

int check_range_turret(int centerX, int centerY, int coordX, int coordY)
{
    int check = pow((coordX - centerX), 2) + pow((coordY - centerY), 2);
    int range = 250;

    if (check <= pow(range, 2))
        return (0);
    else
        return (1);
}

int get_nearest_enemy(scene_t scene, turret_t turret)
{
    int index = 0;
    int distance = INT_MAX;
    int distance_new = 0;
    sfVector2f enemy_f;
    sfVector2i enemy_pos;
    sfVector2i position = (sfVector2i){turret.x, turret.y};

    for (int i = 0; i < scene.in_game->nb_enemies; i++) {
        if (!scene.in_game->arr_enemies[i].is_spawned)
            continue;
        enemy_f = sfSprite_getPosition(scene.in_game->arr_enemies[i].sprite);
        enemy_pos = (sfVector2i){enemy_f.x, enemy_f.y};
        distance_new = sqrt((enemy_pos.x - position.x)
        * (enemy_pos.x - position.x) + (enemy_pos.y - position.y)
        * (enemy_pos.y - position.y));
        if (distance_new < distance) {
            index = i;
            distance = distance_new;
        }
    }
    return (index);
}