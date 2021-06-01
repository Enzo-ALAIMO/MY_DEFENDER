/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** main.c
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include "my_defender.h"
#include "scene.h"
#include "game.h"
#include "map.h"
#include "turret.h"
#include "free.h"
#include "sound.h"

static int set_game(game_t *game)
{
    game->video_mode = (sfVideoMode){1920, 1080, 32};
    game->window = sfRenderWindow_create(game->video_mode,
        "My_defender", sfResize | sfClose, NULL);
    if (!game->window)
        return (84);
    game->volume = 100;
    init_sounds(game);
    game->sprites = malloc(sizeof(sprites_t));
    game->textures = malloc(sizeof(textures_t));
    game->arr_scenes = malloc(sizeof(scene_t) * NB_SCENES);
    game->arr_scenes[MENU_SCENE] = create_scene_menu();
    game->arr_scenes[HTP_SCENE] = create_scene_htp();
    game->arr_scenes[SETTINGS_SCENE] = create_scene_settings();
    game->arr_scenes[SELECTION_SCENE] = create_scene_selection();
    game->arr_scenes[FIRST_LEVEL_SCENE] = create_scene_first_level();
    game->arr_scenes[SECOND_LEVEL_SCENE] = create_scene_second_level();
    game->arr_scenes[THIRD_LEVEL_SCENE] = create_scene_third_level();
    game->arr_scenes[FORTH_LEVEL_SCENE] = create_scene_forth_level();
    game->scene_index = MENU_SCENE;
    return (0);
}

int main(void)
{
    game_t *game = malloc(sizeof(game_t));

    if (game == NULL || set_game(game) == 84)
        return (84);
    set_sprites_map(game->sprites, game->textures);
    set_sprites_turret(game->sprites, game->textures);
    sfSound_setLoop(game->sounds[SOUND_BG], true);
    sfSound_play(game->sounds[SOUND_BG]);
    game_loop(game);
    free_game(game);
    return (0);
}