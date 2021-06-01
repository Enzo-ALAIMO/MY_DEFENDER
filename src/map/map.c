/*
** EPITECH PROJECT, 2020
** Projects
** File description:
** map.c
*/

#include "my_defender.h"
#include <stdlib.h>

char **mem_alloc_2d_array_char(int x, int y)
{
    char **arr = malloc(sizeof(char *) * y);

    if (arr == NULL)
        return (NULL);
    for (int i = 0; i < y; i++) {
        arr[i] = malloc(sizeof(char *) * x);
        if (arr[i] == NULL)
            return (NULL);
    }
    return (arr);
}

char **map_2d_array(char *str, int y, int x)
{
    char **arr = mem_alloc_2d_array_char(y, x);
    int t = 0;

    for (int i = 0; i < y; i++) {
        if (str[t] == '\n')
            t++;
        for (int j = 0; j < x; j++) {
            if (str[t] == '\n')
                break;
            arr[i][j] = str[t];
            t++;
        }
    }
    return (arr);
}