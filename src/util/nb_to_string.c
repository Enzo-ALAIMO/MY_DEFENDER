/*
** EPITECH PROJECT, 2020
** B-MUL-200-PAR-2-1-mydefender-enzo.alaimo
** File description:
** nb_to_string.c
*/

#include <stdlib.h>
#include "util.h"

char *nb_to_string(int nb)
{
    int len = 0;
    int n = 0;
    int is_neg = 0;
    char *str = malloc(sizeof(char) * NB_LEN);

    if (nb < 0) {
        nb *= -1;
        is_neg = 1;
        str[0] = '-';
    }
    n = nb;
    while (n != 0) {
        len++;
        n /= 10;
    }
    for (int i = 0; i < len; i++) {
        str[len - (i + 1 - is_neg)] = (nb % 10) + '0';
        nb = nb / 10;
    }
    str[len + is_neg] = '\0';
    return (str);
}