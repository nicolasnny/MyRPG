/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** Function to delete an entity from the system
*/

#include <stdio.h>
#include "rpg.h"

#include <unistd.h> //tmp

bool remove_entity(system_t *sys, entity_t *e)
{
    for (unsigned int n = 0; 1 << n < __END__; n += 1) {
        remove_entity_from_list(&(sys->component[1 << n]), e);
    }
    remove_entity_from_list(&(sys->e_list), e);
    free_entity(e);
    return true;
}

static bool delete_corners(sokospot_t ***map, int line, int col)
{
    if (line > 0 && col > 0 && map[line - 1][col - 1]->type == ENEMY) {
        map[line - 1][col - 1]->type = EMPTY;
        return true;
    }
    if (line < MAP_HEIGHT - 1 && col > 0 &&
        map[line + 1][col - 1]->type == ENEMY) {
        map[line + 1][col - 1]->type = EMPTY;
        return true;
    }
    if (line < MAP_HEIGHT - 1 && col < WIN_WIDTH - 1
        && map[line + 1][col + 1]->type == ENEMY) {
        map[line + 1][col]->type = EMPTY;
        return true;
    }
    if (line > 0 && col < MAP_WIDTH - 1
        && map[line - 1][col + 1]->type == ENEMY) {
        map[line - 1][col + 1]->type = EMPTY;
        return true;
    }
    return false;
}

static bool delete_around(sokospot_t ***map, int line, int col)
{
    if (line > 0 && map[line - 1][col]->type == ENEMY) {
        map[line - 1][col]->type = EMPTY;
        return true;
    }
    if (col > 0 && map[line][col - 1]->type == ENEMY) {
        map[line][col - 1]->type = EMPTY;
        return true;
    }
    if (line < MAP_HEIGHT - 1 && map[line + 1][col]->type == ENEMY) {
        map[line + 1][col]->type = EMPTY;
        return true;
    }
    if (col < MAP_WIDTH - 1 && map[line][col + 1]->type == ENEMY) {
        map[line][col + 1]->type = EMPTY;
        return true;
    }
    return delete_corners(map, line, col);
}

bool remove_entity_from_map(system_t *sys, sokospot_t ***map, entity_t *e)
{
    sfVector2f map_size = {0};
    int line = 0;
    int col = 0;

    if (map == NULL || e == NULL)
        return false;
    for (unsigned int line = 0; map[line]; line++) {
        for (int i = 0; map[line][i]; i++) {
            if (map[line][i]->type == ENEMY)
                printf("found one -> line: %d | col: %d\n", line, i);
        }
    }
    map_size = get_map_size(sys);
    get_sprite_coords_on_sokomap(&map_size, e->sprite, &line, &col);
    if (line < 0 || col < 0 || col >= MAP_WIDTH || line >= MAP_HEIGHT ||
        map[line][col]->entity == NULL) {
        if (line < 0 || col < 0 || col >= MAP_WIDTH || line >= MAP_HEIGHT)
            return false;
        if (delete_around(map, line, col))
            return true;
        dprintf(2, "[WARNING] could not delete entity on sokomap as ");
        dprintf(2, "coordonates weren't matching any entity\n");
        return false;
    }
    map[line][col]->type = EMPTY;
    return true;
}