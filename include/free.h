/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** free.h
*/

#ifndef FREE_H
#define FREE_H

#include "my_defender.h"

void free_game(game_t *game);
void free_scene(scene_t scene);
void free_in_game(in_game_t *in_game);
void free_enemy(in_game_t *in_game);
void free_turret(in_game_t *in_game);

#endif