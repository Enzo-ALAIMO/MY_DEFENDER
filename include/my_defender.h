/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** my_defender.h
*/

#ifndef MY_DEFENDER_H
#define MY_DEFENDER_H

#define _GNU_SOURCE

static int const WINDOW_WIDTH = 1920;
static int const WINDOW_HEIGHT = 1080;

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct btn_path_s {
    char *sprite;
    char *sprite_over;
    char *sprite_click;
} btn_path_t;

typedef struct button_s {
    sfRectangleShape *rect;
    sfVector2f pos;
    sfVector2f size;
    sfSprite *sprite;
    sfSprite *over_sprite;
    sfSprite *click_sprite;
    bool draw_over;
    bool draw_click;
    void (*on_click)();
} button_t;

typedef struct text_s {
    sfText *text;
    sfFont *font;
    sfVector2f pos;
    char *text_content;
} text_t;

typedef struct map_s {
    char *str_map;
    char **map_str;
    char *filepath;
    int x;
    int y;
} map_t;

typedef struct sprites_s {
    sfSprite **arr_spr;
    sfSprite **arr_tur;
} sprites_t;

typedef struct textures_s {
    sfTexture **my_arr_spr;
    sfTexture **my_arr_tur;
} textures_t;

typedef struct turret_s {
    int index;
    int x;
    int y;
    int range;
    int damage;
    int slow;
    float rotation;
    float time;
    float fire_rate;
    bool can_shoot;
    int tier;
    int type;
    int price;
} turret_t;

enum name_sprites {
    SPR_DECOR,
    SPR_SPAWNER,
    SPR_PATH,
    SPR_BASE,
    SPR_TURRET,
    NB_SPR
};

enum name_turret {
    SPR_MEDIUM_1,
    SPR_MEDIUM_2,
    SPR_MEDIUM_3,
    SPR_HEAVY_1,
    SPR_HEAVY_2,
    SPR_HEAVY_3,
    SPR_SNIPER_1,
    SPR_SNIPER_2,
    SPR_SNIPER_3,
    SPR_FREEZE,
    N_SPR
};

typedef struct path_s {
    int size_path;
    int index;
    sfVector2i *path;
    sfVector2i *pos_used;
    sfVector2i pos;
} path_t;

typedef struct spawner_s {
    int nb_enemies_to_spawn;
    int nb_enemies_spawned;
    float time_between_spawn;
    sfVector2i *path;
    float time;
} spawner_t;

typedef struct enemy_s {
    bool is_spawned;
    sfSprite *sprite;
    sfRectangleShape *hitbox;
    int speed;
    int damage;
    int health;
    int gold;
    int init_speed;
    sfVector2i *path;
    int nb_waypoint;
    int current_waypoint;
    sfIntRect rect;
    float time;
    float time_between_animation;
} enemy_t;

typedef struct player_s {
    int gold;
    int heal;
    int turret_select;
    int tier;
} player_t;

typedef struct in_game_s {
    player_t player;
    sfSprite *hud;
    int nb_waves;
    spawner_t spawner;
    enemy_t *arr_enemies;
    turret_t *arr_turret;
    int nb_enemies;
    int nb_turrets;
} in_game_t;

typedef struct scene_s {
    int nb_buttons;
    int nb_texts;
    button_t *arr_buttons;
    text_t *arr_texts;
    sfSprite *background;
    map_t *map;
    in_game_t *in_game;
    sfClock *clock_dt;
    sfFont *font;
    sfSprite *spr_pause;
    sfSprite *spr_defeat;
    bool pause;
    bool defeat;
    bool change;
    void (*event)();
    void (*update)();
    void (*draw)();
} scene_t;

typedef struct game_s {
    sfRenderWindow *window;
    sfVideoMode video_mode;
    sfEvent event;
    int scene_index;
    scene_t *arr_scenes;
    sprites_t *sprites;
    textures_t *textures;
    int volume;
    sfSound **sounds;
} game_t;

#endif