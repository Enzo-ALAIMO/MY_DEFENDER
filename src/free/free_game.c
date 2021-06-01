/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** free_game.c
*/

#include <stdlib.h>
#include "my_defender.h"
#include "scene.h"
#include "free.h"

static void free_sprites(sprites_t *sprites)
{
    for (int i = 0; i < NB_SPR; i++)
        sfSprite_destroy(sprites->arr_spr[i]);
    free(sprites->arr_spr);
    for (int i = 0; i < N_SPR; i++)
        sfSprite_destroy(sprites->arr_tur[i]);
    free(sprites->arr_tur);
    free(sprites);
}

static void free_textures(textures_t *textures)
{
    for (int i = 0; i < NB_SPR; i++)
        sfTexture_destroy(textures->my_arr_spr[i]);
    free(textures->my_arr_spr);
    for (int i = 0; i < N_SPR; i++)
        sfTexture_destroy(textures->my_arr_tur[i]);
    free(textures->my_arr_tur);
    free(textures);
}

void free_game(game_t *game)
{
    if (game->arr_scenes != NULL) {
        for (int i = 0; i < NB_SCENES; i++)
            free_scene(game->arr_scenes[i]);
        free(game->arr_scenes);
    }
    if (game->sprites != NULL)
        free_sprites(game->sprites);
    if (game->textures != NULL)
        free_textures(game->textures);
    free(game);
}