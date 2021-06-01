/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** sound.h
*/

#ifndef SOUND_H
#define SOUND_H

#include "my_defender.h"

enum sounds {
    SOUND_BG,
    SOUND_DEFEAT,
    SOUND_SHOT,
    NB_SOUND
};

void init_sounds(game_t *game);

#endif