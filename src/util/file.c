/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** write_to_file.c
*/

#include <stdio.h>
#include "util.h"
#include "scene.h"
#include "my.h"

void write_score_to_file(int index, int score)
{
    FILE *file = NULL;

    if (index == FIRST_LEVEL_SCENE)
        file = fopen("./easy_score.txt", "w+");
    if (index == SECOND_LEVEL_SCENE)
        file = fopen("./medium_score.txt", "w+");
    if (index == THIRD_LEVEL_SCENE)
        file = fopen("./hard_score.txt", "w+");
    if (index == FORTH_LEVEL_SCENE)
        file = fopen("./insane_score.txt", "w+");
    fwrite(nb_to_string(score), my_strlen(nb_to_string(score)), 1, file);
    fclose(file);
}

char *get_score_from_file(char const *file_name)
{
    FILE *file = fopen(file_name, "r");
    char buffer[NB_LEN];
    char *buf = NULL;

    if (file == NULL)
        return ("No score");
    fread(&buffer, sizeof(char), NB_LEN, file);
    buffer[NB_LEN] = '\0';
    for (int i = 0; i < NB_LEN; i++)
        if (buffer[i] < '0' || buffer[i] > '9')
            buffer[i] = '\0';
    fclose(file);
    buf = my_strdup(buffer);
    return (buf);
}