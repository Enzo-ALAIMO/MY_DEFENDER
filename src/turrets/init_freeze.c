
/*
** EPITECH PROJECT, 2020
** Projects
** File description:
** init_turret_t3.c
*/

#include "my_defender.h"
#include "util.h"
#include "interface.h"

turret_t freeze(void)
{
    turret_t freeze = {0};

    freeze.can_shoot = false;
    freeze.index = SPR_FREEZE;
    freeze.slow = 50;
    freeze.damage = 0;
    freeze.price = 100;
    freeze.type = 4;
    return (freeze);
}