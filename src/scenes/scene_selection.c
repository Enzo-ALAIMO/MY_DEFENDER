/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** scene_selection.c
*/

#include <stdlib.h>
#include "my_defender.h"
#include "interface.h"
#include "event.h"
#include "draw.h"
#include "buttons_functions.h"
#include "scene.h"
#include "update.h"
#include "util.h"

static sfSprite *create_selection_background(void)
{
    sfTexture *texture = sfTexture_createFromFile(
        "./assets/menu/map_select.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfFalse);
    return (sprite);
}

static text_t *create_texts(scene_t scene)
{
    text_t *arr_texts = malloc(sizeof(scene_t) * NB_TXT_SEL);

    if (arr_texts == NULL)
        return (NULL);
    arr_texts[TXT_EASY] = text_init(scene, (sfVector2f){WINDOW_WIDTH / 2 - 100,
        460}, get_score_from_file("./easy_score.txt"));
    arr_texts[TXT_MEDIUM] = text_init(scene, (sfVector2f){WINDOW_WIDTH / 2
        - 100, 560}, get_score_from_file("./medium_score.txt"));
    arr_texts[TXT_HARD] = text_init(scene, (sfVector2f){WINDOW_WIDTH / 2 - 100,
        650}, get_score_from_file("./hard_score.txt"));
    arr_texts[TXT_INSANE] = text_init(scene, (sfVector2f){WINDOW_WIDTH / 2
        - 100, 760}, get_score_from_file("./insane_score.txt"));
    arr_texts[TXT_EASY_T] = text_init(scene, (sfVector2f){WINDOW_WIDTH / 2
        - 100, 410}, "Easy :");
    arr_texts[TXT_MEDIUM_T] = text_init(scene, (sfVector2f){WINDOW_WIDTH / 2
        - 100, 510}, "Medium :");
    arr_texts[TXT_HARD_T] = text_init(scene, (sfVector2f){WINDOW_WIDTH / 2
        - 100, 610}, "Hard :");
    arr_texts[TXT_INSANE_T] = text_init(scene, (sfVector2f){WINDOW_WIDTH / 2
        - 100, 710}, "Insane :");
    return (arr_texts);
}

static button_t *create_buttons(scene_t scene)
{
    button_t *arr_buttons = malloc(sizeof(button_t) * scene.nb_buttons);
    char *path[] = {"./assets/menu/easy.png", "./assets/menu/medium.png",
        "./assets/menu/hard.png", "./assets/menu/insane.png",
        "./assets/menu/over_map.png", "./assets/menu/click_map.png",
        "./assets/menu/set_return.png", "./assets/menu/set_over.png",
        "./assets/menu/set_click.png"};

    if (arr_buttons == NULL)
        return (NULL);
    arr_buttons[EASY_BTN_SEL] = button_init((sfVector2f){515, 405},
    set_btn_path(path, 0, 4, 5), &change_scene);
    arr_buttons[MEDIUM_BTN_SEL] = button_init((sfVector2f){515, 800},
    set_btn_path(path, 1, 4, 5), &change_scene);
    arr_buttons[HARD_BTN_SEL] = button_init((sfVector2f){1400, 405},
    set_btn_path(path, 2, 4, 5), &change_scene);
    arr_buttons[INSANE_BTN_SEL] = button_init((sfVector2f){1400, 800},
    set_btn_path(path, 3, 4, 5), &change_scene);
    arr_buttons[RETURN_BTN_SEL] = button_init((sfVector2f){WINDOW_WIDTH / 2,
    925}, set_btn_path(path, 6, 7, 8), &change_scene);
    return (arr_buttons);
}

scene_t create_scene_selection(void)
{
    scene_t scene = {0};

    scene.nb_buttons = NB_BTN_SELECTION;
    scene.nb_texts = NB_TXT_SEL;
    scene.arr_buttons = create_buttons(scene);
    scene.font = sfFont_createFromFile("./assets/font/font.TTF");
    scene.arr_texts = create_texts(scene);
    scene.background = create_selection_background();
    scene.event = &event_selection;
    scene.update = &update_selection;
    scene.draw = &draw_selection;
    return (scene);
}