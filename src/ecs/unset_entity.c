/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** unset_entity
*/

#include <stdbool.h>
#include <stdlib.h>
#include "rpg.h"

void move_list_to_entity(e_list_t **list, e_list_t *prev, entity_t *e)
{
    while (*list != NULL && (*list)->entity->id != e->id) {
        prev = *list;
        *list = (*list)->next;
    }
    (void)prev;
}

static bool change_head(e_list_t **list)
{
    e_list_t *cur = *list;

    *list = (*list)->next;
    free(cur);
    return true;
}

bool remove_entity_from_list(e_list_t **list, entity_t *e)
{
    e_list_t *start = *list;
    e_list_t *prev = NULL;

    move_list_to_entity(list, prev, e);
    if (*list == NULL) {
        *list = start;
        return false;
    }
    if (prev == NULL) {
        return change_head(list);
    }
    prev->next = (*list)->next;
    free(*list);
    *list = start;
    return true;
}

bool unset_entity(system_t *sys, entity_t *e, int component)
{
    for (unsigned int n = 0; 1 << n < __END__; n += 1) {
        if ((component & 1 << n) &&
            !remove_entity_from_list(&(sys->component[1 << n]), e)) {
            return false;
        }
    }
    return true;
}