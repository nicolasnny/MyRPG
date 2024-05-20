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

    printf("in kill function\n");
    (void)state;
    if (player == NULL || entity == NULL)
        return 0;
    if (ennemy_in_range(player->entity, entity)) {
        printf("/* sword sound */");
        printf("You killed %s !\n", entity->name);
        remove_entity(param->sys, entity);
        clean_list(player);
        return 1;
    }
    clean_list(player);
    return 1;
}
