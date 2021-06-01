/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** util_level.c
*/

#include "my_defender.h"
#include "scene.h"
#include "interface.h"
#include "buttons_functions.h"

in_game_t *create_in_game(void)
{
    in_game_t *in_game = malloc(sizeof(in_game_t));

    if (in_game == NULL)
        return (NULL);
    in_game->nb_waves = 1;
    in_game->nb_enemies = 5;
    in_game->nb_turrets = 0;
    in_game->hud = NULL;
    in_game->arr_enemies = NULL;
    in_game->arr_turret = NULL;
    return (in_game);
}

text_t *create_level_texts(scene_t scene)
{
    text_t *arr_texts = malloc(sizeof(scene_t) * NB_TXT);

    if (arr_texts == NULL)
        return (NULL);
    arr_texts[TXT_LIFES] = text_init(scene, (sfVector2f){970, 950}, "5");
    arr_texts[TXT_GOLDS] = text_init(scene, (sfVector2f){1300, 950}, "100");
    arr_texts[TXT_WAVES] = text_init(scene, (sfVector2f){690, 945}, "1");
    arr_texts[TXT_T_ONE] = text_init(scene, (sfVector2f){1805, 118}, "20");
    arr_texts[TXT_T_TWO] = text_init(scene, (sfVector2f){1620, 305}, "25");
    arr_texts[TXT_T_THREE] = text_init(scene, (sfVector2f){1805, 500}, "30");
    arr_texts[TXT_T_FOUR] = text_init(scene, (sfVector2f){1610, 686}, "100");
    return (arr_texts);
}

static button_t *create_level_buttons_part_two(button_t *arr_buttons,
    char **path)
{
    arr_buttons[TURRET_TWO_BTN_LEVEL] = button_init((sfVector2f){1790, 342},
    set_btn_path(path, IMG_T2, IMG_OVER_TURRET, IMG_CLICK_TURRET),
    &select_turret);
    arr_buttons[TURRET_THREE_BTN_LEVEL] = button_init((sfVector2f){1695, 535},
    set_btn_path(path, IMG_T3, IMG_OVER_TURRET, IMG_CLICK_TURRET),
    &select_turret);
    arr_buttons[TURRET_FOUR_BTN_LEVEL] = button_init((sfVector2f){1790, 720},
    set_btn_path(path, IMG_T4, IMG_OVER_TURRET, IMG_CLICK_TURRET),
    &select_turret);
    arr_buttons[RESUME_BTN_LEVEL] = button_init((sfVector2f){960, 301},
    set_btn_path(path, IMG_RESUME, IMG_PAUSE_OVER, IMG_PAUSE_CLICK),
    &resume_game);
    arr_buttons[MENU_BTN_LEVEL] = button_init((sfVector2f){960, 509},
    set_btn_path(path, IMG_MENU, IMG_PAUSE_OVER, IMG_PAUSE_CLICK),
    &return_to_menu);
    arr_buttons[LEAVE_BTN_LEVEL] = button_init((sfVector2f){960, 723},
    set_btn_path(path, IMG_LEAVE, IMG_PAUSE_OVER, IMG_PAUSE_CLICK),
    &exit_game);
    return (arr_buttons);
}

button_t *create_level_buttons(scene_t scene)
{
    button_t *arr_buttons = malloc(sizeof(button_t) * scene.nb_buttons);
    char *path[] = {"./assets/in_game/upgrade.png",
    "./assets/in_game/hud_t1.png", "./assets/in_game/hud_t2.png",
    "./assets/in_game/hud_t3.png", "./assets/in_game/hud_t4.png",
    "./assets/in_game/click_turret.png", "./assets/in_game/click_upgrade.png",
    "./assets/in_game/over_turret.png",
    "./assets/in_game/over_upgrade.png", "./assets/in_game/resume.png",
    "./assets/in_game/go_to_menu.png", "./assets/in_game/quit.png",
    "./assets/in_game/pause_over.png", "./assets/in_game/pause_click.png"};

    arr_buttons[UPGRADE_BTN_LEVEL] = button_init((sfVector2f){1750, 950},
    set_btn_path(path, IMG_UPGRADE, IMG_OVER_UPGRADE, IMG_CLICK_UPGRADE),
    &upgrade_turret);
    arr_buttons[TURRET_ONE_BTN_LEVEL] = button_init((sfVector2f){1695, 155},
    set_btn_path(path, IMG_T1, IMG_OVER_TURRET, IMG_CLICK_TURRET),
    &select_turret);
    arr_buttons = create_level_buttons_part_two(arr_buttons, path);
    return (arr_buttons);
}