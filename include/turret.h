/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** turret.h
*/

#ifndef TURRET_H
#define TURRET_H

#include "my_defender.h"

void set_sprites_turret(sprites_t *turret, textures_t *my_textures);
turret_t *display_turret_map(sprites_t *arr_sprites, turret_t *arr_turret,
    sfVector2f mouse, scene_t scene);
int check_turret_tile(map_t *map, sfVector2f mouse);
int get_nb_turrets(char *str_map);
turret_t set_focus(turret_t turret, enemy_t *enemy);
int check_range_turret(int centerX, int centerY, int coordX, int coordY);
int get_nearest_enemy(scene_t scene, turret_t turret);
turret_t medium_1(void);
turret_t medium_2(void);
turret_t medium_3(void);
turret_t heavy_1(void);
turret_t heavy_2(void);
turret_t heavy_3(void);
turret_t sniper_1(void);
turret_t sniper_2(void);
turret_t sniper_3(void);
turret_t freeze(void);
int get_turret_price(game_t *game);
turret_t get_turret(player_t player);
int get_turret_sprite_index(player_t player);
void change_turret_price_text(game_t *game);

#endif