/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-nicolas.nunney
** File description:
** fisherman.c
*/

#include "rpg.h"
#include "struct.h"
#include "associative.h"

static int get_nb_mob(parameters_t *param, int component)
{
    e_list_t *mobs = get_entities(param->sys, component);
    int cpt = 0;

    while (mobs) {
        cpt++;
        mobs = mobs->next;
    }
}

bool fisherman(parameters_t *param)
{
    int initial_nb_mob = get_nb_mob(param, MOB);
    int actual_nb_mob = get_nb_mob(param, MOB | VISIBLE);

    if (initial_nb_mob - actual_nb_mob > 2) {
        return true;
    }
    return false;
}
