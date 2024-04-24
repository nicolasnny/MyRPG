/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** Get entities from the system
*/

#include <stddef.h>
#include "rpg.h"
#include "struct.h"

static bool check_entity(entity_t *entity, system_t *sys, int component)
{
    for (unsigned int n = 1; n != __END__; n <<= 1) {
        if ((component << n & 1) &&
            !entity_in_list(sys->component[n], entity)) {
            return false;
        }
    }
    return true;
}

e_list_t *get_entities(system_t *sys, int component)
{
    e_list_t *s_list = sys->e_list;
    e_list_t *rep_list = NULL;

    while (s_list != NULL) {
        if (check_entity(s_list->entity, sys, component)) {
            push_to_list(&rep_list, s_list->entity);
        }
        s_list = s_list->next;
    }
    return rep_list;
}
