/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-nicolas.nunney
** File description:
** destroy_entity.c
*/

#include "rpg.h"
#include "struct.h"

static bool destroy_component_list(int component, system_t *system)
{
    e_list_t *temp = system->component[component];

    while (temp) {
        free_entity(temp->entity);
        temp = temp->next;
    }
    return true;
}

int destroy_entities(system_t *system, int component)
{
    for (unsigned int n = 0; 1 << n < __END__; n++) {
        if ((component & 1 << n) &&
            !destroy_component_list(1 << n, system)) {
            return ERROR;
        }
    }
    return SUCCESS;
}
