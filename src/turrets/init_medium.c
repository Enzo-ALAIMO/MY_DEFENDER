
/*
** EPITECH PROJECT, 2020
** Projects
** File description:
** init_medium.c
*/

#include "my_defender.h"
#include "util.h"
#include "interface.h"

turret_t medium_1(void)
{
    turret_t medium_1 = {0};

    medium_1.range = 250;
    medium_1.damage = 1;
    medium_1.index = SPR_MEDIUM_1;
    medium_1.price = 20;
    medium_1.tier = 1;
    medium_1.type = 1;
    return (medium_1);
}

turret_t medium_2(void)
{
    turret_t medium_2 = {0};

    medium_2.range = 250;
    medium_2.damage = 2;
    medium_2.index = SPR_MEDIUM_2;
    medium_2.price = 35;
    medium_2.tier = 2;
    medium_2.type = 1;
    return (medium_2);

}

turret_t medium_3(void)
{
    turret_t medium_3 = {0};

    medium_3.range = 250;
    medium_3.damage = 3;
    medium_3.index = SPR_MEDIUM_3;
    medium_3.price = 45;
    medium_3.tier = 3;
    medium_3.type = 1;
    return (medium_3);
}