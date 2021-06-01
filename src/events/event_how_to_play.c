/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** event_how_to_play.c
*/

#include "my_defender.h"
#include "scene.h"
#include "interface.h"

static void buttons_actions(game_t *game)
{
    button_t *arr_buttons = game->arr_scenes[HTP_SCENE].arr_buttons;
    sfVector2f mouse_pos = (sfVector2f){game->event.mouseButton.x,
                            game->event.mouseButton.y};

    if (button_is_hover(arr_buttons[RETURN_BTN_HTP], mouse_pos, game)) {
        arr_buttons[RETURN_BTN_HTP].draw_click = true;
        arr_buttons[RETURN_BTN_HTP].on_click(game, MENU_SCENE);
    } else
        arr_buttons[RETURN_BTN_HTP].draw_click = false;
}

void event_htp(game_t *game)
{
    if (game->event.type == sfEvtMouseButtonPressed)
        if (game->event.mouseButton.button == sfMouseLeft)
            buttons_actions(game);
}