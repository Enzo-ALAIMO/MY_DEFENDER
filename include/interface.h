/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** my_defender.h
*/

#ifndef INTERFACE_H
#define INTERFACE_H

#include <SFML/Graphics.h>
#include <stdbool.h>
#include "my_defender.h"

enum img_path_sett_index {
    IMG_S_RETURN,
    IMG_S_PLUS,
    IMG_S_MOINS,
    IMG_S_R_L,
    IMG_S_R_M,
    IMG_S_R_H,
    IMG_S_F_L,
    IMG_S_F_M,
    IMG_S_F_H,
    IMG_S_OVER,
    IMG_S_CLICK,
    IMG_S_V_OVER,
    IMG_S_V_CLICK,
    NB_IMG_SETTINGS
};

enum img_path_level_index {
    IMG_UPGRADE,
    IMG_T1,
    IMG_T2,
    IMG_T3,
    IMG_T4,
    IMG_CLICK_TURRET,
    IMG_CLICK_UPGRADE,
    IMG_OVER_TURRET,
    IMG_OVER_UPGRADE,
    IMG_RESUME,
    IMG_MENU,
    IMG_LEAVE,
    IMG_PAUSE_OVER,
    IMG_PAUSE_CLICK,
    NB_IMG_LEVEL
};

btn_path_t set_btn_path(char **path, int sprite, int sprite_over,
    int sprite_click);
button_t button_init(sfVector2f pos, btn_path_t btn_path, void (*on_click)());
bool button_is_hover(button_t button,
    sfVector2f click_position, game_t *game);
void update_text_string(text_t text, char const *content);
text_t text_init(scene_t const scene, sfVector2f const pos,
    char const *content);
sfSprite *create_sprite(char *path);

#endif