/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** Get entities from the system
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "rpg.h"
#include "struct.h"

static bool check_entity(entity_t *entity, system_t *sys, int component)
{
    for (unsigned int n = 0; 1 << n < __END__; n += 1) {
        if ((component & 1 << n) &&
            !entity_in_list(sys->component[1 << n], entity)) {
            return false;
        }
    }
    return true;
}

unsigned int get_first_component_matching(int component)
{
    unsigned int i = 0;

    while (1 << i < __END__) {
        if (component & 1 << i)
            return i;
        i++;
    }
    return i;
}

e_list_t *get_entities(system_t *sys, int component)
{
    e_list_t *ret_list = NULL;
    e_list_t *tmp_list = NULL;
    unsigned int i = get_first_component_matching(component);

    if (1 << i == __END__)
        return NULL;
    tmp_list = sys->component[1 << i];
    while (tmp_list) {
        if (check_entity(tmp_list->entity, sys, component))
            push_to_list(&ret_list, tmp_list->entity);
        tmp_list = tmp_list->next;
    }
    return ret_list;
}

entity_t *get_entity_by_name(system_t *sys, char const *name)
{
    e_list_t *list = sys->e_list;

    while (list) {
        if (list->entity->name &&
            strcmp(list->entity->name, name) == 0) {
            return list->entity;
        }
        list = list->next;
    }
    return NULL;
}
