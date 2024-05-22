/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** Function to delete an entity from the system
*/

#include <stdio.h>
#include "rpg.h"

bool remove_entity(system_t *sys, entity_t *e)
{
    for (unsigned int n = 0; 1 << n < __END__; n += 1) {
        remove_entity_from_list(&(sys->component[1 << n]), e);
    }
    remove_entity_from_list(&(sys->e_list), e);
    free_entity(e);
    return true;
}

bool remove_entity_from_map(sokospot_t ***map, entity_t *e)
{
    sokospot_t *spot = NULL;

    if (map == NULL || e == NULL)
        return false;
    spot = get_entity_spot(map, e);
    if (spot == NULL) {
        dprintf(2, "[WARNING] could not delete entity on sokomap as ");
        dprintf(2, "coordonates weren't matching any entity\n");
        return false;
    }
    spot->type = EMPTY;
    return true;
}
