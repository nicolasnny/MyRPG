/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** Functions related to killing system
*/

#include <stdbool.h>
#include <stdio.h>
#include "rpg.h"

int kill_entity(parameters_t *param, entity_t *entity, bool state)
{
    e_list_t *player = get_entities(param->sys, PLAYER | VISIBLE);

    (void)state;
    if (player == NULL || entity == NULL)
        return ERROR;
    if (ennemy_in_range(player->entity, entity)) {
        printf("/* sword sound */");
        printf("You killed %s !\n", entity->name);
        unset_entity(param->sys, entity, VISIBLE);
        clean_list(player);
        return 1;
    }
    clean_list(player);
    return SUCCESS;
}
