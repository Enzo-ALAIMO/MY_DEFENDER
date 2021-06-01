/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** text.c
*/

#include "my_defender.h"
#include "my.h"

void update_text_string(text_t text, char const *content)
{
    sfText_setString(text.text, content);
}

text_t text_init(scene_t const scene, sfVector2f const pos, char const *content)
{
    text_t text = {0};

    text.font = scene.font;
    text.pos = pos;
    text.text = sfText_create();
    text.text_content = my_strdup(content);
    sfText_setFont(text.text, text.font);
    sfText_setPosition(text.text, text.pos);
    sfText_setString(text.text, text.text_content);
    sfText_setCharacterSize(text.text, 50);
    return (text);
}