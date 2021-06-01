/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** spawner.h
*/

#ifndef SPAWNER_H
#define SPAWNER_H

#include "my_defender.h"

spawner_t spawner_init(scene_t scene, in_game_t *in_game);
void update_spawner_timer(scene_t scene, sfTime dt);
void new_wave(scene_t scene);

#endif