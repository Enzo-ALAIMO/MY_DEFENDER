/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** enemy.h
*/

#ifndef ENEMY_H
#define ENEMY_H

#include "my_defender.h"

enemy_t enemy_init(void);
void move_enemy(in_game_t *in_game, int i, sfTime dt);
void enemy_damage_player(scene_t scene, in_game_t *in_game, int i);
void play_animation_enemy(in_game_t *in_game, int i, sfTime dt);

#endif