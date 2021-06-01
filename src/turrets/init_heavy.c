/*
** EPITECH PROJECT, 2020
** Projects
** File description:
** init_turret_t2.c
*/

#include "my_defender.h"
#include "util.h"
#include "interface.h"

turret_t heavy_1(void)
{
    turret_t heavy_1 = {0};

    heavy_1.can_shoot = false;
    heavy_1.range = 250;
    heavy_1.damage = 3;
    heavy_1.index = SPR_HEAVY_1;
    heavy_1.price = 25;
    heavy_1.tier = 1;
    heavy_1.type = 2;
    return (heavy_1);
}

turret_t heavy_2(void)
{
    turret_t heavy_2 = {0};

    heavy_2.can_shoot = false;
    heavy_2.range = 250;
    heavy_2.damage = 4;
    heavy_2.index = SPR_HEAVY_2;
    heavy_2.price = 40;
    heavy_2.tier = 2;
    heavy_2.type = 2;
    return (heavy_2);
}

turret_t heavy_3(void)
{
    turret_t heavy_3 = {0};

    heavy_3.can_shoot = false;
    heavy_3.range = 250;
    heavy_3.damage = 5;
    heavy_3.index = SPR_HEAVY_3;
    heavy_3.price = 55;
    heavy_3.tier = 3;
    heavy_3.type = 2;
    return (heavy_3);
}