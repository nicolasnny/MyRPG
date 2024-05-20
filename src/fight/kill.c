/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** Functions related to killing system
*/

#include <stdbool.h>
#include <stdio.h>
#include "rpg.h"

bool kill_entity(system_t *sys, entity_t *entity, bool state)
{
    e_list_t *player = get_entities(sys, PLAYER | VISIBLE);

    printf("in kill function\n");
    (void)state;
    if (player == NULL || entity == NULL)
        return false;
    if (ennemy_in_range(player->entity, entity)) {
        printf("/* sword sound */");
        printf("You killed %s !\n", entity->name);
        remove_entity(sys, entity);
        clean_list(player);
        return true;
    }
    clean_list(player);
    return false;
}
