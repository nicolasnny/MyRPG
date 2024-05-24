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
    e_list_t *temp = mobs;
    int cpt = 0;

    while (temp) {
        cpt++;
        temp = temp->next;
    }
    clean_list(mobs);
    return cpt;
}

bool fisherman(parameters_t *param)
{
    int initial_nb_mob = get_nb_mob(param, MOB);
    int actual_nb_mob = get_nb_mob(param, MOB | VISIBLE);
    entity_t *quest = get_entity_by_name(param->sys, "fisherman_quest");
    entity_t *reset_btn = get_entity_by_name(param->sys, "reset_quest");

    if (initial_nb_mob - actual_nb_mob >= 2) {
        reset_quest(param, NULL, false);
        return true;
    }
    set_entity(quest, param->sys, VISIBLE);
    set_entity(reset_btn, param->sys, VISIBLE);
    set_quest_pos(param);
    return false;
}

int launch_fisherman(parameters_t *param, entity_t *entity, bool state)
{
    param->actual_quest = &fisherman;
    (void)entity;
    (void)state;
    return SUCCESS;
}
