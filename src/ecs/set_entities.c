/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-nicolas.nunney
** File description:
** set_entities.c
*/

#include <stdbool.h>
#include "struct.h"
#include "rpg.h"

bool set_entity(entity_t *entity, system_t *system, int component)
{
    for (unsigned int n = 0; 1 << n < __END__; n += 1) {
        if ((component & 1 << n) &&
            !push_to_list(&(system->component[1 << n]), entity)) {
            return false;
        }
    }
    return true;
}
