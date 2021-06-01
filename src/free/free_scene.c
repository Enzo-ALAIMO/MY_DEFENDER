/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** free_scene.c
*/

#include <stdlib.h>
#include "my_defender.h"
#include "free.h"
#include "map.h"

static void free_button(button_t button)
{
    sfSprite_destroy(button.over_sprite);
    sfSprite_destroy(button.sprite);
    sfRectangleShape_destroy(button.rect);
}

static void free_text(text_t text)
{
    sfText_destroy(text.text);
    free(text.text_content);
}

static void free_map(map_t *map)
{
    if (map->map_str != NULL) {
        for (int i = 0; i < get_y(map->str_map); i++)
            free(map->map_str[i]);
        free(map->map_str);
    }
    if (map->str_map != NULL)
        free(map->str_map);
    free(map);
}

void free_scene(scene_t scene)
{
    if (scene.arr_buttons != NULL) {
        for (int i = 0; i < scene.nb_buttons; i++)
            free_button(scene.arr_buttons[i]);
        free(scene.arr_buttons);
    }
    if (scene.arr_texts != NULL) {
        for (int i = 0; i < scene.nb_texts; i++)
            free_text(scene.arr_texts[i]);
        free(scene.arr_texts);
    }
    if (scene.background != NULL)
        sfSprite_destroy(scene.background);
    if (scene.map != NULL)
        free_map(scene.map);
    if (scene.in_game != NULL)
        free_in_game(scene.in_game);
    if (scene.clock_dt != NULL)
        sfClock_destroy(scene.clock_dt);
    if (scene.font != NULL)
        sfFont_destroy(scene.font);
}