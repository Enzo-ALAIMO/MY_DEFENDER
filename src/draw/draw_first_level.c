/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** draw_first_level.c
*/

#include "my_defender.h"
#include "scene.h"
#include "map.h"
#include "turret.h"

static void draw_drag_turret(game_t *game)
{
    sfVector2f mouse_pos = sfRenderWindow_mapPixelToCoords(game->window,
        sfMouse_getPositionRenderWindow(game->window),
        sfRenderWindow_getView(game->window));

    if (game->arr_scenes[game->scene_index].in_game->player.turret_select
        != 0) {
        sfSprite_setPosition(game->sprites->arr_tur[get_turret_sprite_index(
            game->arr_scenes[game->scene_index].in_game->player)], mouse_pos);
        sfSprite_setRotation(game->sprites->arr_tur[get_turret_sprite_index(
            game->arr_scenes[game->scene_index].in_game->player)],
            0);
        sfSprite_setOrigin(game->sprites->arr_tur[get_turret_sprite_index(
            game->arr_scenes[game->scene_index].in_game->player)],
            (sfVector2f){175, 175});
        sfRenderWindow_drawSprite(game->window,
            game->sprites->arr_tur[get_turret_sprite_index(
            game->arr_scenes[game->scene_index].in_game->player)], NULL);
    }
}

static void draw_turret(game_t *game, int i)
{
    scene_t scene = game->arr_scenes[game->scene_index];
    turret_t turret = scene.in_game->arr_turret[i];

    if (turret.index != -1) {
        sfSprite_setPosition(game->sprites->arr_tur[turret.index],
            (sfVector2f){turret.x, turret.y});
        sfSprite_setRotation(game->sprites->arr_tur[turret.index],
            turret.rotation);
        sfRenderWindow_drawSprite(game->window,
            game->sprites->arr_tur[turret.index], NULL);
    }
}

static void draw_buttons(game_t *game, scene_t scene)
{
    for (int i = 0; i < scene.nb_buttons; i++) {
        if (scene.arr_buttons[i].sprite == NULL || (!scene.pause
            && i > NB_BTN_LEVEL - 4))
            continue;
        if (i > NB_BTN_LEVEL - 4 && scene.defeat)
            continue;
        sfRenderWindow_drawSprite(game->window,
            scene.arr_buttons[i].sprite, NULL);
        if (scene.arr_buttons[i].draw_over && !scene.arr_buttons[i].draw_click)
            sfRenderWindow_drawSprite(game->window,
                scene.arr_buttons[i].over_sprite, NULL);
        if (scene.arr_buttons[i].draw_over && scene.arr_buttons[i].draw_click)
            sfRenderWindow_drawSprite(game->window,
                scene.arr_buttons[i].click_sprite, NULL);
    }
}

void draw_first_level(game_t *game)
{
    scene_t scene = game->arr_scenes[game->scene_index];

    sfRenderWindow_drawSprite(game->window, scene.in_game->hud, NULL);
    display_map(scene.map, game->sprites, game->window);
    for (int i = 0; i < scene.in_game->nb_enemies; i++)
        if (scene.in_game->arr_enemies[i].is_spawned)
            sfRenderWindow_drawSprite(game->window,
                scene.in_game->arr_enemies[i].sprite, NULL);
    for (int i = 0; i < get_nb_turrets(scene.map->str_map); i++)
        draw_turret(game, i);
    draw_drag_turret(game);
    for (int i = 0; i < scene.nb_texts; i++)
        sfRenderWindow_drawText(game->window, scene.arr_texts[i].text, NULL);
    if (scene.pause && !scene.defeat)
        sfRenderWindow_drawSprite(game->window, scene.spr_pause, NULL);
    draw_buttons(game, scene);
    if (scene.defeat)
        sfRenderWindow_drawSprite(game->window, scene.spr_defeat, NULL);
}