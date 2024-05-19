/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** Functions related to killing system
*/

#include <stdbool.h>
#include <stdio.h>
#include "rpg.h"

bool kill_entity(system_t *sys, entity_t *entity)
{
    e_list_t *player = get_entities(sys, PLAYER | VISIBLE);

    if (player == NULL || entity == NULL)
        return false;
    if (ennemy_in_range(player->entity, entity)) {
        printf("/* sword sound */");
        printf("You killed %s !\n", entity->name);
        printf("add function to delete entity");
        return true;
    }
    return false;
}
