/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** update_level_button.c
*/

#include "my_defender.h"
#include "scene.h"
#include "interface.h"

static void update_buttons(button_t *arr_buttons, sfVector2f mouse_pos,
    game_t *game)
{
    arr_buttons[UPGRADE_BTN_LEVEL].draw_over =
        button_is_hover(arr_buttons[UPGRADE_BTN_LEVEL], mouse_pos, game);
    arr_buttons[TURRET_ONE_BTN_LEVEL].draw_over =
        button_is_hover(arr_buttons[TURRET_ONE_BTN_LEVEL], mouse_pos, game);
    arr_buttons[TURRET_TWO_BTN_LEVEL].draw_over =
        button_is_hover(arr_buttons[TURRET_TWO_BTN_LEVEL], mouse_pos, game);
    arr_buttons[TURRET_THREE_BTN_LEVEL].draw_over =
        button_is_hover(arr_buttons[TURRET_THREE_BTN_LEVEL], mouse_pos, game);
    arr_buttons[TURRET_FOUR_BTN_LEVEL].draw_over =
        button_is_hover(arr_buttons[TURRET_FOUR_BTN_LEVEL], mouse_pos, game);
    arr_buttons[RESUME_BTN_LEVEL].draw_over =
        button_is_hover(arr_buttons[RESUME_BTN_LEVEL], mouse_pos, game);
    arr_buttons[MENU_BTN_LEVEL].draw_over =
        button_is_hover(arr_buttons[MENU_BTN_LEVEL], mouse_pos, game);
    arr_buttons[LEAVE_BTN_LEVEL].draw_over =
        button_is_hover(arr_buttons[LEAVE_BTN_LEVEL], mouse_pos, game);
}

void update_level_button(game_t *game)
{
    button_t *arr_buttons = game->arr_scenes[game->scene_index].arr_buttons;
    sfVector2f mouse_pos =
        (sfVector2f){sfMouse_getPositionRenderWindow(game->window).x,
        sfMouse_getPositionRenderWindow(game->window).y};

    update_buttons(arr_buttons, mouse_pos, game);
}