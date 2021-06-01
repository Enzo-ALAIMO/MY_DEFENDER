/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** event_settings.c
*/

#include "my_defender.h"
#include "scene.h"
#include "interface.h"

static void event_buttons_part_three(button_t *arr_buttons, sfVector2f mouse_pos,
    game_t *game)
{
    if (button_is_hover(arr_buttons[FPS_H_BTN_SETT], mouse_pos, game)) {
        arr_buttons[FPS_H_BTN_SETT].draw_click = true;
        arr_buttons[FPS_H_BTN_SETT].on_click(game, 120);
    } else
        arr_buttons[FPS_H_BTN_SETT].draw_click = false;
}

static void event_buttons_part_two(button_t *arr_buttons, sfVector2f mouse_pos,
    game_t *game)
{
    if (button_is_hover(arr_buttons[MEDIUM_BTN_SETT], mouse_pos, game)) {
        arr_buttons[MEDIUM_BTN_SETT].draw_click = true;
        arr_buttons[MEDIUM_BTN_SETT].on_click(game, 1280, 720);
    } else
        arr_buttons[MEDIUM_BTN_SETT].draw_click = false;
    if (button_is_hover(arr_buttons[HIGH_BTN_SETT], mouse_pos, game)) {
        arr_buttons[HIGH_BTN_SETT].draw_click = true;
        arr_buttons[HIGH_BTN_SETT].on_click(game, 1920, 1080);
    } else
        arr_buttons[HIGH_BTN_SETT].draw_click = false;
    if (button_is_hover(arr_buttons[FPS_L_BTN_SETT], mouse_pos, game)) {
        arr_buttons[FPS_L_BTN_SETT].draw_click = true;
        arr_buttons[FPS_L_BTN_SETT].on_click(game, 30);
    } else
        arr_buttons[FPS_L_BTN_SETT].draw_click = false;
    if (button_is_hover(arr_buttons[FPS_M_BTN_SETT], mouse_pos, game)) {
        arr_buttons[FPS_M_BTN_SETT].draw_click = true;
        arr_buttons[FPS_M_BTN_SETT].on_click(game, 60);
    } else
        arr_buttons[FPS_M_BTN_SETT].draw_click = false;
    event_buttons_part_three(arr_buttons, mouse_pos, game);
}

static void event_buttons(button_t *arr_buttons, sfVector2f mouse_pos,
    game_t *game)
{
    if (button_is_hover(arr_buttons[RETURN_BTN_SETT], mouse_pos, game)) {
        arr_buttons[RETURN_BTN_SETT].draw_click = true;
        arr_buttons[RETURN_BTN_SETT].on_click(game, MENU_SCENE);
    } else
        arr_buttons[RETURN_BTN_SETT].draw_click = false;
    if (button_is_hover(arr_buttons[VOL_UP_BTN_SETT], mouse_pos, game)) {
        arr_buttons[VOL_UP_BTN_SETT].draw_click = true;
        arr_buttons[VOL_UP_BTN_SETT].on_click(game, 1);
    } else
        arr_buttons[VOL_UP_BTN_SETT].draw_click = false;
    if (button_is_hover(arr_buttons[VOL_DOWN_BTN_SETT], mouse_pos, game)) {
        arr_buttons[VOL_DOWN_BTN_SETT].draw_click = true;
        arr_buttons[VOL_DOWN_BTN_SETT].on_click(game, 0);
    } else
        arr_buttons[VOL_DOWN_BTN_SETT].draw_click = false;
    if (button_is_hover(arr_buttons[LOW_BTN_SETT], mouse_pos, game)) {
        arr_buttons[LOW_BTN_SETT].draw_click = true;
        arr_buttons[LOW_BTN_SETT].on_click(game, 800, 600);
    } else
        arr_buttons[LOW_BTN_SETT].draw_click = false;
    event_buttons_part_two(arr_buttons, mouse_pos, game);
}

void event_settings(game_t *game)
{
    button_t *arr_buttons = game->arr_scenes[game->scene_index].arr_buttons;
    sfVector2f mouse_pos = (sfVector2f){game->event.mouseButton.x,
                            game->event.mouseButton.y};

    if (game->event.type == sfEvtMouseButtonPressed)
        if (game->event.mouseButton.button == sfMouseLeft)
            event_buttons(arr_buttons, mouse_pos, game);
}