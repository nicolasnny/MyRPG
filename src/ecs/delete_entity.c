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

// static bool delete_corners(sokospot_t ***map, int line, int col)
// {
//     if (line > 0 && col > 0 && map[line - 1][col - 1]->type == ENEMY) {
//         map[line - 1][col - 1]->type = EMPTY;
//         return true;
//     }
//     if (line < MAP_HEIGHT - 1 && col > 0 &&
//         map[line + 1][col - 1]->type == ENEMY) {
//         map[line + 1][col - 1]->type = EMPTY;
//         return true;
//     }
//     if (line < MAP_HEIGHT - 1 && col < WIN_WIDTH - 1
//         && map[line + 1][col + 1]->type == ENEMY) {
//         map[line + 1][col]->type = EMPTY;
//         return true;
//     }
//     if (line > 0 && col < MAP_WIDTH - 1
//         && map[line - 1][col + 1]->type == ENEMY) {
//         map[line - 1][col + 1]->type = EMPTY;
//         return true;
//     }
//     return false;
// }

// static bool delete_around(sokospot_t ***map, int line, int col)
// {
//     if (line > 0 && map[line - 1][col]->type == ENEMY) {
//         map[line - 1][col]->type = EMPTY;
//         return true;
//     }
//     if (col > 0 && map[line][col - 1]->type == ENEMY) {
//         map[line][col - 1]->type = EMPTY;
//         return true;
//     }
//     if (line < MAP_HEIGHT - 1 && map[line + 1][col]->type == ENEMY) {
//         map[line + 1][col]->type = EMPTY;
//         return true;
//     }
//     if (col < MAP_WIDTH - 1 && map[line][col + 1]->type == ENEMY) {
//         map[line][col + 1]->type = EMPTY;
//         return true;
//     }
//     return delete_corners(map, line, col);
// }

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