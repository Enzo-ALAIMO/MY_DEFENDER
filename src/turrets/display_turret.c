/*
** EPITECH PROJECT, 2020
** Projects
** File description:
** display_turret.c
*/

#include "my_defender.h"
#include <SFML/Graphics.h>
#include "turret.h"

int get_nb_turrets(char *str_map)
{
    int nb = 0;

    for (int i = 0; str_map[i]; i++)
        if (str_map[i] == 'O')
            nb++;
    return (nb);
}

void set_sprites_turret(sprites_t *sprite, textures_t *my_textures)
{
    sfVector2f scale = {0.3, 0.3};
    char *img_path[] = { "./assets/in_game/turret_1.png",
        "./assets/in_game/turret_1-2.png",
        "./assets/in_game/turret_1-3.png", "./assets/in_game/turret_2.png",
        "./assets/in_game/turret_2-2.png", "./assets/in_game/turret_2-3.png",
        "./assets/in_game/turret_3.png", "./assets/in_game/turret_3-2.png",
        "./assets/in_game/turret_3-3.png", "./assets/in_game/turret_4.png" };

    sprite->arr_tur = malloc(sizeof(*sprite->arr_tur) * N_SPR);
    for (int i = 0; i < N_SPR; i++)
        sprite->arr_tur[i] = sfSprite_create();
    my_textures->my_arr_tur = malloc(sizeof(*my_textures->my_arr_tur) * N_SPR);
    for (int i = 0; i < N_SPR; i++)
        my_textures->my_arr_tur[i] = sfTexture_createFromFile(img_path[i],
        NULL);
    for (int i = 0; i < N_SPR; i++)
        sfSprite_setTexture(sprite->arr_tur[i], my_textures->my_arr_tur[i],
        sfFalse);
    for (int i = 0; i < N_SPR; i++)
        sfSprite_setScale(sprite->arr_tur[i], scale);
}

turret_t set_focus(turret_t turret, enemy_t *enemy)
{
    sfVector2f enemy_pos_f = sfSprite_getPosition(enemy->sprite);
    sfVector2i enemy_pos = (sfVector2i){enemy_pos_f.x + 48, enemy_pos_f.y + 48};
    sfVector2i position = (sfVector2i){turret.x, turret.y};
    const float PI = 3.14159265;
    float dx = position.x - enemy_pos.x;
    float dy = position.y - enemy_pos.y;
    float rotation = (atan2f(dy, dx)) * 180 / PI;

    turret.can_shoot = false;
    enemy->speed = enemy->init_speed;
    if (check_range_turret(enemy_pos.x, enemy_pos.y,
        position.x, position.y) == 0) {
        turret.rotation = rotation;
        turret.can_shoot = true;
        if (turret.slow != 0 && enemy->speed - turret.slow >= 0)
            enemy->speed -= turret.slow;
    }
    return (turret);
}

int check_turret_tile(map_t *map, sfVector2f mouse)
{
    int x = mouse.x / 96;
    int y = mouse.y / 96;

    if (map->map_str[y][x] == 'O') {
        map->map_str[y][x] = 'T';
        return (0);
    }
    return (1);
}

turret_t *display_turret_map(sprites_t *arr_sprites, turret_t *arr_turret,
    sfVector2f mouse, scene_t scene)
{
    int x = mouse.x / 96;
    int y = mouse.y / 96;

    for (int i = 0; i < scene.in_game->nb_turrets; i++)
        if (arr_turret[i].index == -1) {
            arr_turret[i] = get_turret(scene.in_game->player);
            arr_turret[i].x = x * 96 + 48;
            arr_turret[i].y = y * 96 + 48;
            arr_turret[i].fire_rate = 1;
            sfSprite_setOrigin(arr_sprites->arr_tur[arr_turret[i].index],
                (sfVector2f){175, 175});
            break;
        }
    return (arr_turret);
}