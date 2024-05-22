/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** Functions to get precise sokospots
*/

#include "rpg.h"

static sokospot_t *search_in_line(sokospot_t **line, int id)
{
    for (unsigned int col = 0; line[col]; col++) {
        if (line[col]->entity && line[col]->entity->id == id)
            return line[col];
    }
    return NULL;
}

sokospot_t *get_entity_spot(sokospot_t ***map, entity_t *e)
{
    sokospot_t *res = NULL;

    for (unsigned int l = 0; map[l] != NULL; l++) {
        res = search_in_line(map[l], e->id);
        if (res)
            return res;
    }
    return NULL;
}

sokospot_t *get_player_spot(sokospot_t ***map)
{
    unsigned int col = 0;

    for (int l = 0; map[l] != NULL; l++) {
        for (col = 0; map[l][col] && map[l][col]->type != PLAYER_CHAR; col++)
            continue;
        if (map[l][col])
            return map[l][col];
    }
    return NULL;
}
