/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** event_level_button.c
*/

#include "my_defender.h"
#include "scene.h"
#include "interface.h"

static void event_buttons_part_two(button_t *arr_buttons, sfVector2f mouse_pos,
    game_t *game)
{
    if (button_is_hover(arr_buttons[TURRET_THREE_BTN_LEVEL], mouse_pos, game)) {
        arr_buttons[TURRET_THREE_BTN_LEVEL].draw_click = true;
        arr_buttons[TURRET_THREE_BTN_LEVEL].on_click(game, 3);
    } else
        arr_buttons[TURRET_THREE_BTN_LEVEL].draw_click = false;
    if (button_is_hover(arr_buttons[TURRET_FOUR_BTN_LEVEL], mouse_pos, game)) {
        arr_buttons[TURRET_FOUR_BTN_LEVEL].draw_click = true;
        arr_buttons[TURRET_FOUR_BTN_LEVEL].on_click(game, 4);
    } else
        arr_buttons[TURRET_FOUR_BTN_LEVEL].draw_click = false;
}

static void event_buttons_pause(button_t *arr_buttons, sfVector2f mouse_pos,
    game_t *game)
{
    if (!game->arr_scenes[game->scene_index].pause
        || game->arr_scenes[game->scene_index].defeat)
        return;
    if (button_is_hover(arr_buttons[RESUME_BTN_LEVEL], mouse_pos, game)) {
        arr_buttons[RESUME_BTN_LEVEL].draw_click = true;
        arr_buttons[RESUME_BTN_LEVEL].on_click(game);
    } else
        arr_buttons[RESUME_BTN_LEVEL].draw_click = false;
    if (button_is_hover(arr_buttons[MENU_BTN_LEVEL], mouse_pos, game)) {
        arr_buttons[MENU_BTN_LEVEL].draw_click = true;
        arr_buttons[MENU_BTN_LEVEL].on_click(game);
    } else
        arr_buttons[MENU_BTN_LEVEL].draw_click = false;
    if (button_is_hover(arr_buttons[LEAVE_BTN_LEVEL], mouse_pos, game)) {
        arr_buttons[LEAVE_BTN_LEVEL].draw_click = true;
        arr_buttons[LEAVE_BTN_LEVEL].on_click(game);
    } else
        arr_buttons[LEAVE_BTN_LEVEL].draw_click = false;
}

static void event_buttons(button_t *arr_buttons, sfVector2f mouse_pos,
    game_t *game)
{
    if (button_is_hover(arr_buttons[UPGRADE_BTN_LEVEL], mouse_pos, game)) {
        arr_buttons[UPGRADE_BTN_LEVEL].draw_click = true;
        arr_buttons[UPGRADE_BTN_LEVEL].on_click(game);
    } else
        arr_buttons[UPGRADE_BTN_LEVEL].draw_click = false;
    if (button_is_hover(arr_buttons[TURRET_ONE_BTN_LEVEL], mouse_pos, game)) {
        arr_buttons[TURRET_ONE_BTN_LEVEL].draw_click = true;
        arr_buttons[TURRET_ONE_BTN_LEVEL].on_click(game, 1);
    } else
        arr_buttons[TURRET_ONE_BTN_LEVEL].draw_click = false;
    if (button_is_hover(arr_buttons[TURRET_TWO_BTN_LEVEL], mouse_pos, game)) {
        arr_buttons[TURRET_TWO_BTN_LEVEL].draw_click = true;
        arr_buttons[TURRET_TWO_BTN_LEVEL].on_click(game, 2);
    } else
        arr_buttons[TURRET_TWO_BTN_LEVEL].draw_click = false;
    event_buttons_part_two(arr_buttons, mouse_pos, game);
    event_buttons_pause(arr_buttons, mouse_pos, game);
}

void event_level_button(game_t *game)
{
    button_t *arr_buttons = game->arr_scenes[game->scene_index].arr_buttons;
    sfVector2f mouse_pos = (sfVector2f){game->event.mouseButton.x,
                            game->event.mouseButton.y};

    event_buttons(arr_buttons, mouse_pos, game);
}