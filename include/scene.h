/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** scene.h
*/

#ifndef SCENE_H
#define SCENE_H

#include "my_defender.h"

enum scenes_names {
    MENU_SCENE,
    HTP_SCENE,
    SETTINGS_SCENE,
    SELECTION_SCENE,
    FIRST_LEVEL_SCENE,
    SECOND_LEVEL_SCENE,
    THIRD_LEVEL_SCENE,
    FORTH_LEVEL_SCENE,
    NB_SCENES
};

enum btn_menu {
    PLAY_BTN_MENU,
    HTP_BTN_MENU,
    SETTINGS_BTN_MENU,
    EXIT_BTN_MENU,
    NB_BTN_MENU
};

enum btn_htp {
    RETURN_BTN_HTP,
    NB_BTN_HTP
};

enum btn_settings {
    RETURN_BTN_SETT,
    VOL_UP_BTN_SETT,
    VOL_DOWN_BTN_SETT,
    LOW_BTN_SETT,
    MEDIUM_BTN_SETT,
    HIGH_BTN_SETT,
    FPS_L_BTN_SETT,
    FPS_M_BTN_SETT,
    FPS_H_BTN_SETT,
    NB_BTN_SETT
};

enum btn_selection {
    EASY_BTN_SEL,
    MEDIUM_BTN_SEL,
    HARD_BTN_SEL,
    INSANE_BTN_SEL,
    RETURN_BTN_SEL,
    NB_BTN_SELECTION
};

enum btn_level {
    UPGRADE_BTN_LEVEL,
    TURRET_ONE_BTN_LEVEL,
    TURRET_TWO_BTN_LEVEL,
    TURRET_THREE_BTN_LEVEL,
    TURRET_FOUR_BTN_LEVEL,
    RESUME_BTN_LEVEL,
    MENU_BTN_LEVEL,
    LEAVE_BTN_LEVEL,
    NB_BTN_LEVEL
};

enum txt_selection {
    TXT_EASY,
    TXT_MEDIUM,
    TXT_HARD,
    TXT_INSANE,
    TXT_EASY_T,
    TXT_MEDIUM_T,
    TXT_HARD_T,
    TXT_INSANE_T,
    NB_TXT_SEL
};

enum txt_level {
    TXT_LIFES,
    TXT_GOLDS,
    TXT_WAVES,
    TXT_T_ONE,
    TXT_T_TWO,
    TXT_T_THREE,
    TXT_T_FOUR,
    NB_TXT
};

scene_t create_scene_menu(void);
scene_t create_scene_htp(void);
scene_t create_scene_first_level(void);
sfSprite *create_spr_pause(void);
sfSprite *create_spr_defeat(void);
in_game_t *create_in_game(void);
text_t *create_level_texts(scene_t scene);
button_t *create_level_buttons(scene_t scene);
button_t *create_sett_buttons(scene_t scene);
scene_t create_scene_settings(void);
scene_t create_scene_selection(void);
scene_t create_scene_second_level(void);
scene_t create_scene_third_level(void);
scene_t create_scene_forth_level(void);

#endif