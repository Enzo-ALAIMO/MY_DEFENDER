/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** event_menu.c
*/

#include "my_defender.h"
#include "scene.h"
#include "interface.h"

static void buttons_actions(game_t *game, button_t *arr_buttons,
    sfVector2f mouse_pos)
{
    if (button_is_hover(arr_buttons[PLAY_BTN_MENU], mouse_pos, game)) {
        arr_buttons[PLAY_BTN_MENU].draw_click = true;
        arr_buttons[PLAY_BTN_MENU].on_click(game, SELECTION_SCENE);
    } else
        arr_buttons[PLAY_BTN_MENU].draw_click = false;
    if (button_is_hover(arr_buttons[HTP_BTN_MENU], mouse_pos, game)) {
        arr_buttons[HTP_BTN_MENU].draw_click = true;
        arr_buttons[HTP_BTN_MENU].on_click(game, HTP_SCENE);
    } else
        arr_buttons[HTP_BTN_MENU].draw_click = false;
    if (button_is_hover(arr_buttons[SETTINGS_BTN_MENU], mouse_pos, game)) {
        arr_buttons[SETTINGS_BTN_MENU].draw_click = true;
        arr_buttons[SETTINGS_BTN_MENU].on_click(game, SETTINGS_SCENE);
    } else
        arr_buttons[SETTINGS_BTN_MENU].draw_click = false;
    if (button_is_hover(arr_buttons[EXIT_BTN_MENU], mouse_pos, game)) {
        arr_buttons[EXIT_BTN_MENU].draw_click = true;
        arr_buttons[EXIT_BTN_MENU].on_click(game);
    } else
        arr_buttons[EXIT_BTN_MENU].draw_click = false;
}

void event_menu(game_t *game)
{
    button_t *arr_buttons = game->arr_scenes[MENU_SCENE].arr_buttons;
    sfVector2f mouse_pos = (sfVector2f){game->event.mouseButton.x,
                            game->event.mouseButton.y};

    if (game->event.type == sfEvtMouseButtonPressed)
        if (game->event.mouseButton.button == sfMouseLeft)
            buttons_actions(game, arr_buttons, mouse_pos);
}