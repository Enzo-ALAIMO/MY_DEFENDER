/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** map.h
*/

#ifndef MAP_H
#define MAP_H

#include "my_defender.h"

#include <stdbool.h>

char **mem_alloc_2d_array_char(int y, int x);
char **map_2d_array(char *str, int y, int x);
int get_y(char *map);
int get_x(char *map);
char **init_map(char *filepath, map_t *map);
void set_sprites_map(sprites_t *sprites, textures_t *textures);
void display_map(map_t *map, sprites_t *sprites, sfRenderWindow *window);
void display_decor(map_t *map, sprites_t *sprites, sfRenderWindow *window);
void display_spawner(map_t *map, sprites_t *sprites, sfRenderWindow *window);
void display_path(map_t *map, sprites_t *sprites, sfRenderWindow *window);
void display_base(map_t *map, sprites_t *sprites, sfRenderWindow *window);
void display_turret(map_t *map, sprites_t *sprites, sfRenderWindow *window);
sfVector2i *get_path(map_t *map);
int get_size_path(map_t *map);
bool is_used(path_t *path, sfVector2i pos);
sfVector2i check_corner(path_t *path, map_t *map, sfVector2i pos);
sfVector2i *handle_corner(path_t *path, map_t *map);
sfVector2i check_border(path_t *path, map_t *map, sfVector2i v, sfVector2i h);
sfVector2i *handle_border(path_t *path, map_t *map);
sfVector2i check_inside(path_t *path, map_t *map, sfVector2i v, sfVector2i h);
sfVector2i *handle_inside(path_t *path, map_t *map);

#endif