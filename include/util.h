/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** util.h
*/

#ifndef UTIL_H
#define UTIL_H

static const int NB_LEN = 10;

char *nb_to_string(int nb);
int get_random_int(int bound);
void write_score_to_file(int index, int score);
char *get_score_from_file(char const *file_name);

#endif


