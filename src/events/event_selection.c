/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** event_selection.c
*/

#include "my_defender.h"
#include "scene.h"
#include "interface.h"

static void buttons_actions_part_two(game_t *game, button_t *arr_buttons,
    sfVector2f mouse_pos)
{
    if (button_is_hover(arr_buttons[RETURN_BTN_SEL], mouse_pos, game)) {
        arr_buttons[RETURN_BTN_SEL].draw_click = true;
        arr_buttons[RETURN_BTN_SEL].on_click(game, MENU_SCENE);
    } else
        arr_buttons[RETURN_BTN_SEL].draw_click = false;
}

static void buttons_actions(game_t *game, button_t *arr_buttons,
    sfVector2f mouse_pos)
{
    if (button_is_hover(arr_buttons[EASY_BTN_SEL], mouse_pos, game)) {
        arr_buttons[EASY_BTN_SEL].draw_click = true;
        arr_buttons[EASY_BTN_SEL].on_click(game, FIRST_LEVEL_SCENE);
    } else
        arr_buttons[EASY_BTN_SEL].draw_click = false;
    if (button_is_hover(arr_buttons[MEDIUM_BTN_SEL], mouse_pos, game)) {
        arr_buttons[MEDIUM_BTN_SEL].draw_click = true;
        arr_buttons[MEDIUM_BTN_SEL].on_click(game, SECOND_LEVEL_SCENE);
    } else
        arr_buttons[MEDIUM_BTN_SEL].draw_click = false;
    if (button_is_hover(arr_buttons[HARD_BTN_SEL], mouse_pos, game)) {
        arr_buttons[HARD_BTN_SEL].draw_click = true;
        arr_buttons[HARD_BTN_SEL].on_click(game, THIRD_LEVEL_SCENE);
    } else
        arr_buttons[HARD_BTN_SEL].draw_click = false;
    if (button_is_hover(arr_buttons[INSANE_BTN_SEL], mouse_pos, game)) {
        arr_buttons[INSANE_BTN_SEL].draw_click = true;
        arr_buttons[INSANE_BTN_SEL].on_click(game, FORTH_LEVEL_SCENE);
    } else
        arr_buttons[INSANE_BTN_SEL].draw_click = false;
    buttons_actions_part_two(game, arr_buttons, mouse_pos);
}

void event_selection(game_t *game)
{
    button_t *arr_buttons = game->arr_scenes[SELECTION_SCENE].arr_buttons;
    sfVector2f mouse_pos = (sfVector2f){game->event.mouseButton.x,
                            game->event.mouseButton.y};

    if (game->event.type == sfEvtMouseButtonPressed)
        if (game->event.mouseButton.button == sfMouseLeft)
            buttons_actions(game, arr_buttons, mouse_pos);
}