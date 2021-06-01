/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** update_selection.c
*/

#include "my_defender.h"
#include "scene.h"
#include "interface.h"

static void buttons_hover(game_t *game)
{
    button_t *arr_buttons = game->arr_scenes[game->scene_index].arr_buttons;
    sfVector2f mouse_pos =
        (sfVector2f){sfMouse_getPositionRenderWindow(game->window).x,
        sfMouse_getPositionRenderWindow(game->window).y};

    arr_buttons[EASY_BTN_SEL].draw_over =
        button_is_hover(arr_buttons[EASY_BTN_SEL], mouse_pos, game);
    arr_buttons[MEDIUM_BTN_SEL].draw_over =
        button_is_hover(arr_buttons[MEDIUM_BTN_SEL], mouse_pos, game);
    arr_buttons[HARD_BTN_SEL].draw_over =
        button_is_hover(arr_buttons[HARD_BTN_SEL], mouse_pos, game);
    arr_buttons[INSANE_BTN_SEL].draw_over =
        button_is_hover(arr_buttons[INSANE_BTN_SEL], mouse_pos, game);
    arr_buttons[RETURN_BTN_SEL].draw_over =
        button_is_hover(arr_buttons[RETURN_BTN_SEL], mouse_pos, game);
}

void update_selection(game_t *game)
{
    if (game->scene_index != SELECTION_SCENE)
        return;
    buttons_hover(game);
}