/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** event_first_level.c
*/

#include <SFML/Audio.h>
#include "my_defender.h"
#include "scene.h"
#include "interface.h"
#include "turret.h"
#include "event.h"
#include "util.h"
#include "sound.h"

void event_first_level(game_t *game)
{
    scene_t scene = game->arr_scenes[game->scene_index];
    sfVector2f mouse =
        sfRenderWindow_mapPixelToCoords(game->window,
        (sfVector2i){game->event.mouseButton.x, game->event.mouseButton.y},
        sfRenderWindow_getView(game->window));

    if (game->event.type == sfEvtMouseButtonPressed) {
        if (game->event.mouseButton.button == sfMouseLeft) {
            event_level_button(game);
            if (scene.in_game->player.gold >= get_turret_price(game)) {
                if (scene.in_game->player.turret_select != 0
                    && check_turret_tile(scene.map, mouse) == 0) {
                    scene.in_game->arr_turret = display_turret_map(
                        game->sprites, scene.in_game->arr_turret, mouse, scene);
                    scene.in_game->player.gold -= get_turret_price(game);
                    scene.in_game->player.turret_select = 0;
                }
            }
        }
    }
    if (game->event.type == sfEvtKeyReleased) {
        if (game->event.key.code == sfKeyEscape) {
            game->arr_scenes[game->scene_index].pause =
                !game->arr_scenes[game->scene_index].pause;
            sfClock_restart(game->arr_scenes[game->scene_index].clock_dt);
        }
        if (game->event.key.code == sfKeySpace &&
            game->arr_scenes[game->scene_index].defeat) {
            sfSound_play(game->sounds[SOUND_DEFEAT]);
            write_score_to_file(game->scene_index, scene.in_game->nb_waves);
            game->arr_scenes[game->scene_index].change = true;
        }
    }
}