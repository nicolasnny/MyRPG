/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** Get entities from the system
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "rpg.h"
#include "struct.h"

static void add_list(e_list_t **new_list, e_list_t *src)
{
    e_list_t *new = NULL;

    while (src != NULL) {
        new = malloc(sizeof(e_list_t));
        if (new == NULL) {
            perror("add list malloc failed");
            return;
        }
        new->entity = src->entity;
        new->next = *new_list;
        *new_list = new;
        src = src->next;
    }
}

static e_list_t *get_pot_list(system_t *sys, int component)
{
    e_list_t *list = NULL;

    for (unsigned int n = 0; n << 1 < __END__; n += 1) {
        if (component & 1 << n) {
            add_list(&list, sys->component[1 << n]);
        }
    }
    return list;
}

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

e_list_t *get_entities(system_t *sys, int component)
{
    e_list_t *s_list = get_pot_list(sys, component);
    e_list_t *rep_list = NULL;

    while (s_list != NULL) {
        if (check_entity(s_list->entity, sys, component)) {
            push_to_list(&rep_list, s_list->entity);
        }
        s_list = s_list->next;
    }
    return rep_list;
}
