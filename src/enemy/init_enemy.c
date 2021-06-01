/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** init_enemy.c
*/

#include "my_defender.h"
#include "util.h"

sfSprite *create_sprite(char *path)
{
    sfTexture *texture = sfTexture_createFromFile(path, NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setScale(sprite, (sfVector2f){0.8, 0.8});
    sfSprite_setTexture(sprite, texture, sfFalse);
    return (sprite);
}

static enemy_t triangle(void)
{
    enemy_t enemy;

    enemy.is_spawned = false;
    enemy.damage = 0;
    enemy.gold = 5;
    enemy.health = 5;
    enemy.hitbox = NULL;
    enemy.path = NULL;
    enemy.nb_waypoint = 0;
    enemy.current_waypoint = 0;
    enemy.speed = 150;
    enemy.init_speed = 150;
    enemy.sprite = create_sprite("./assets/in_game/enemy_1.png");
    enemy.time = 0;
    enemy.time_between_animation = 1;
    enemy.rect = (sfIntRect){0, 0, 120, 120};
    return (enemy);
}

static enemy_t square(void)
{
    enemy_t enemy;

    enemy.is_spawned = false;
    enemy.damage = 0;
    enemy.gold = 10;
    enemy.health = 10;
    enemy.hitbox = NULL;
    enemy.path = NULL;
    enemy.nb_waypoint = 0;
    enemy.current_waypoint = 0;
    enemy.speed = 110;
    enemy.init_speed = 110;
    enemy.sprite = create_sprite("./assets/in_game/enemy_2.png");
    enemy.time = 0;
    enemy.time_between_animation = 1;
    enemy.rect = (sfIntRect){0, 0, 120, 120};
    return (enemy);
}

static enemy_t pentagone(void)
{
    enemy_t enemy;

    enemy.is_spawned = false;
    enemy.damage = 0;
    enemy.gold = 15;
    enemy.health = 20;
    enemy.hitbox = NULL;
    enemy.path = NULL;
    enemy.nb_waypoint = 0;
    enemy.current_waypoint = 0;
    enemy.speed = 70;
    enemy.init_speed = 70;
    enemy.sprite = create_sprite("./assets/in_game/enemy_3.png");
    enemy.time = 0;
    enemy.time_between_animation = 1;
    enemy.rect = (sfIntRect){0, 0, 120, 120};
    return (enemy);
}

enemy_t enemy_init(void)
{
    enemy_t enemy;

    switch (get_random_int(2)) {
        case 0:
            enemy = triangle();
            break;
        case 1:
            enemy = square();
            break;
        case 2:
            enemy = pentagone();
            break;
        default:
            enemy = triangle();
            break;
    }
    return (enemy);
}