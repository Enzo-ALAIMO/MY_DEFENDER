/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** sound.c
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include "my_defender.h"
#include "sound.h"

static sfSoundBuffer **init_sounds_buffers(void)
{
    sfSoundBuffer **s_buff = malloc(sizeof(*s_buff) * NB_SOUND);

    s_buff[SOUND_BG] =
        sfSoundBuffer_createFromFile("./assets/sounds/bg_music.wav");
    s_buff[SOUND_DEFEAT] =
        sfSoundBuffer_createFromFile("./assets/sounds/defeat.wav");
    s_buff[SOUND_SHOT] =
        sfSoundBuffer_createFromFile("./assets/sounds/shot.wav");
    return (s_buff);
}

void init_sounds(game_t *game)
{
    sfSoundBuffer **sounds_buffers = init_sounds_buffers();

    game->sounds = malloc(sizeof(*game->sounds) * NB_SOUND);
    for (int i = 0; i < NB_SOUND; i++) {
        game->sounds[i] = sfSound_create();
        sfSound_setBuffer(game->sounds[i], sounds_buffers[i]);
        sfSound_setVolume(game->sounds[i], game->volume);
    }
}