/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** game_loop.c
*/

#include <SFML/Graphics.h>
#include "my_defender.h"
#include "free.h"
#include "buttons_functions.h"

static void game_event(game_t *game, scene_t current_scene)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (current_scene.event != NULL)
            current_scene.event(game);
    }
}

void game_loop(game_t *game)
{
    scene_t current_scene;

    while (sfRenderWindow_isOpen(game->window)) {
        current_scene = game->arr_scenes[game->scene_index];
        game_event(game, current_scene);
        if (game->arr_scenes[game->scene_index].change) {
            change_scene(game, 0);
            continue;
        }
        if (current_scene.update != NULL) {
            current_scene.update(game);
            if (current_scene.in_game
                && current_scene.in_game->player.heal <= 0) {
                game->arr_scenes[game->scene_index].pause = true;
                game->arr_scenes[game->scene_index].defeat = true;
            }
        }
        sfRenderWindow_clear(game->window, sfBlack);
        if (current_scene.draw != NULL)
            current_scene.draw(game);
        sfRenderWindow_display(game->window);
    }
}