/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** update_first_scene.c
*/

#include <SFML/Audio.h>
#include "my_defender.h"
#include "math.h"
#include "map.h"
#include "spawner.h"
#include "enemy.h"
#include "turret.h"
#include "interface.h"
#include "scene.h"
#include "util.h"
#include "update.h"
#include "sound.h"

static void update_enemy(scene_t scene, sfTime dt)
{
    for (int i = 0; i < scene.in_game->nb_enemies; i++) {
        if (scene.in_game->arr_enemies[i].is_spawned) {
            play_animation_enemy(scene.in_game, i, dt);
            move_enemy(scene.in_game, i, dt);
            enemy_damage_player(scene, scene.in_game, i);
        }
    }
}

static void update_turret(game_t *game, scene_t scene, sfTime dt, int index)
{
    for (int i = 0; i < scene.in_game->nb_turrets; i++) {
        if (scene.in_game->arr_turret[i].index != -1) {
            index = get_nearest_enemy(scene, scene.in_game->arr_turret[i]);
            scene.in_game->arr_turret[i] = set_focus(
            scene.in_game->arr_turret[i], &scene.in_game->arr_enemies[index]);
            scene.in_game->arr_turret[i].time += sfTime_asSeconds(dt);
            if (scene.in_game->arr_turret[i].can_shoot
                && scene.in_game->arr_turret[i].time >=
                scene.in_game->arr_turret[i].fire_rate) {
                scene.in_game->arr_enemies[index].health -=
                    scene.in_game->arr_turret[i].damage;
                sfSound_play(game->sounds[SOUND_SHOT]);
                if (scene.in_game->arr_enemies[index].is_spawned == true
                    && scene.in_game->arr_enemies[index].health <= 0) {
                    scene.in_game->player.gold +=
                        scene.in_game->arr_enemies[index].gold;
                    scene.in_game->arr_enemies[index].is_spawned = false;
                }
                scene.in_game->arr_turret[i].time = 0;
            }
        }
    }
}

void update_first_scene(game_t *game)
{
    scene_t scene = game->arr_scenes[game->scene_index];
    sfTime dt = sfClock_getElapsedTime(scene.clock_dt);
    int index = 0;

    sfClock_restart(scene.clock_dt);
    if (!scene.pause) {
        update_spawner_timer(scene, dt);
        update_turret(game, scene, dt, index);
        update_enemy(scene, dt);
        update_text_string(scene.arr_texts[TXT_GOLDS],
            nb_to_string(scene.in_game->player.gold));
        if (scene.in_game->nb_waves >= 10)
            scene.in_game->player.tier = 2;
        if (scene.in_game->nb_waves >= 20)
            scene.in_game->player.tier = 3;
        change_turret_price_text(game);
    }
    update_level_button(game);
}