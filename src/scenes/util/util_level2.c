/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** util_level2.c
*/

#include "my_defender.h"
#include "scene.h"
#include "interface.h"

sfSprite *create_spr_pause(void)
{
    sfTexture *texture = sfTexture_createFromFile(
        "./assets/in_game/pause.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfFalse);
    return (sprite);
}

sfSprite *create_spr_defeat(void)
{
    sfTexture *texture = sfTexture_createFromFile(
        "./assets/in_game/defeat.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfFalse);
    return (sprite);
}