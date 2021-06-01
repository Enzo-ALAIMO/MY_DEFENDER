/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** scene_first_level.c
*/

#include <stdlib.h>
#include "my_defender.h"
#include "event.h"
#include "draw.h"
#include "buttons_functions.h"
#include "scene.h"
#include "map.h"
#include "enemy.h"
#include "spawner.h"
#include "update.h"
#include "turret.h"
#include "game.h"
#include "interface.h"

scene_t create_scene_first_level(void)
{
    scene_t scene = {0};
    in_game_t *in_game = create_in_game();

    scene.nb_buttons = NB_BTN_LEVEL;
    scene.nb_texts = NB_TXT;
    scene.arr_buttons = create_level_buttons(scene);
    scene.font = sfFont_createFromFile("./assets/font/font.TTF");
    scene.arr_texts = create_level_texts(scene);
    scene.map = map_init("./maps/map_4");
    in_game->nb_turrets = get_nb_turrets(scene.map->str_map);
    scene.in_game = in_game_init(scene, in_game);
    scene.clock_dt = sfClock_create();
    scene.spr_pause = create_spr_pause();
    scene.spr_defeat = create_spr_defeat();
    scene.event = &event_first_level;
    scene.update = &update_first_scene;
    scene.draw = &draw_first_level;
    return (scene);
}