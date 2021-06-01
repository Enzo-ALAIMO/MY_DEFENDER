/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** change_scene.c
*/

#include "my_defender.h"
#include "map.h"
#include "scene.h"
#include "game.h"
#include "free.h"
#include "scene.h"
#include "util.h"
#include "interface.h"

void change_scene(game_t *game, int index)
{
    if (game->arr_scenes[game->scene_index].in_game != NULL) {
        free_scene(game->arr_scenes[game->scene_index]);
        if (game->scene_index == FIRST_LEVEL_SCENE)
            game->arr_scenes[game->scene_index] = create_scene_first_level();
        if (game->scene_index == SECOND_LEVEL_SCENE)
            game->arr_scenes[game->scene_index] = create_scene_second_level();
        if (game->scene_index == THIRD_LEVEL_SCENE)
            game->arr_scenes[game->scene_index] = create_scene_third_level();
        if (game->scene_index == FORTH_LEVEL_SCENE)
            game->arr_scenes[game->scene_index] = create_scene_forth_level();
    }
    game->scene_index = index;
    if (game->scene_index == SELECTION_SCENE) {
        update_text_string(game->arr_scenes[game->scene_index]
        .arr_texts[TXT_EASY], get_score_from_file("./easy_score.txt"));
        update_text_string(game->arr_scenes[game->scene_index]
        .arr_texts[TXT_MEDIUM], get_score_from_file("./medium_score.txt"));
        update_text_string(game->arr_scenes[game->scene_index]
        .arr_texts[TXT_HARD], get_score_from_file("./hard_score.txt"));
        update_text_string(game->arr_scenes[game->scene_index]
        .arr_texts[TXT_INSANE], get_score_from_file("./insane_score.txt"));
    }
}