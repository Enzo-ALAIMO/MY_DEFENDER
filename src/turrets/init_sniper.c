/*
** EPITECH PROJECT, 2020
** Projects
** File description:
** init_turret_t3.c
*/

#include "my_defender.h"
#include "util.h"
#include "interface.h"

turret_t sniper_1(void)
{
    turret_t sniper_1 = {0};

    sniper_1.can_shoot = false;
    sniper_1.range = 250;
    sniper_1.damage = 2;
    sniper_1.index = SPR_SNIPER_1;
    sniper_1.price = 30;
    sniper_1.tier = 1;
    sniper_1.type = 3;
    return (sniper_1);
}

turret_t sniper_2(void)
{
    turret_t sniper_2 = {0};

    sniper_2.can_shoot = false;
    sniper_2.range = 250;
    sniper_2.damage = 3;
    sniper_2.index = SPR_SNIPER_2;
    sniper_2.price = 45;
    sniper_2.tier = 2;
    sniper_2.type = 3;
    return (sniper_2);
}

turret_t sniper_3(void)
{
    turret_t sniper_3 = {0};

    sniper_3.can_shoot = false;
    sniper_3.range = 250;
    sniper_3.damage = 4;
    sniper_3.index = SPR_SNIPER_3;
    sniper_3.price = 60;
    sniper_3.tier = 3;
    sniper_3.type = 3;
    return (sniper_3);
}
