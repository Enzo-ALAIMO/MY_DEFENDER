/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** draw_selection.c
*/

#include "my_defender.h"

void draw_selection(game_t *game)
{
    scene_t scene = game->arr_scenes[game->scene_index];

    if (scene.background != NULL)
        sfRenderWindow_drawSprite(game->window, scene.background, NULL);
    for (int i = 0; i < scene.nb_buttons; i++) {
        if (scene.arr_buttons[i].sprite == NULL)
            continue;
        sfRenderWindow_drawSprite(game->window,
            scene.arr_buttons[i].sprite, NULL);
        if (scene.arr_buttons[i].draw_over && !scene.arr_buttons[i].draw_click)
            sfRenderWindow_drawSprite(game->window,
                scene.arr_buttons[i].over_sprite, NULL);
        if (scene.arr_buttons[i].draw_over && scene.arr_buttons[i].draw_click)
            sfRenderWindow_drawSprite(game->window,
                scene.arr_buttons[i].click_sprite, NULL);
    }
    for (int i = 0; i < scene.nb_texts; i++)
        sfRenderWindow_drawText(game->window, scene.arr_texts[i].text, NULL);
}