/*
** EPITECH PROJECT, 2024
** MY_RPG
** File description:
** Get the array representation of the map from the file
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "rpg.h"
#include "my.h"

static sokospot_t *set_sokospot(sokospot_t *spot, char type, entity_t *e)
{
    spot->entity = e;
    spot->type = type;
    return spot;
}

static sokospot_t *create_defaut_sokospot(char type)
{
    sokospot_t *spot = malloc(sizeof(sokospot_t));

    if (spot == NULL) {
        perror("init spot malloc failed");
        return NULL;
    }
    spot->entity = NULL;
    spot->type = EMPTY;
    if (type == OBSTACLE || type == NPC_LIMIT)
        spot->type = type;
    spot->moved_in_frame = false;
    spot->last_pos = (sfVector2f){0};
    return spot;
}

static bool set_list_on_map(sokospot_t ***map, e_list_t *list, char type,
    system_t *sys)
{
    sfVector2f map_size = get_map_size(sys);
    int line = 0;
    int col = 0;

    while (list) {
        get_sprite_coords_on_sokomap(&map_size,
            list->entity->sprite, &line, &col);
        if (line < 0 || col < 0 || line >= MAP_HEIGHT || col >= MAP_WIDTH)
            return false;
        if (map[line][col])
            dprintf(2, "[WARNING] sokospot not null before adding entity\n");
        map[line][col] = set_sokospot(map[line][col], type, list->entity);
        list = list->next;
    }
    return true;
}

static sokospot_t ***fill_sokomap(sokospot_t ***map, system_t *sys)
{
    if (!set_list_on_map(map, get_entities(sys, PLAYER), PLAYER_CHAR, sys)) {
        dprintf(2, "Error: unable to set player on sokomap\n");
        return NULL;
    }
    if (!set_list_on_map(map, get_entities(sys, MOB), ENEMY, sys)) {
        dprintf(2, "Error: unable to set mobs on sokomap\n");
        return NULL;
    }
    if (!set_list_on_map(map, get_entities(sys, NPC), NPC_CHAR, sys)) {
        dprintf(2, "Error: unable to set npcs on sokomap\n");
        return NULL;
    }
    return map;
}

static sokospot_t ***char_to_soko(char **char_map)
{
    sokospot_t ***map =
        calloc(my_strstrlen(char_map) + 1, sizeof(sokospot_t **));

    if (map == NULL) {
        perror("char to soko calloc failed");
        return NULL;
    }
    for (unsigned int line = 0; char_map[line]; line++) {
        map[line] = calloc(strlen(char_map[line]) + 1, sizeof(sokospot_t *));
        if (map[line] == NULL) {
            perror("char to soko line calloc failed");
            return NULL;
        }
        for (unsigned int col = 0; char_map[line][col]; col++) {
            map[line][col] = create_defaut_sokospot(char_map[line][col]);
        }
    }
    return map;
}

static sokospot_t ***transfrom_map(char *buffer, char *sep, system_t *sys)
{
    char **char_map = my_pimp_str_to_wa(buffer, sep);
    sokospot_t ***map = NULL;

    free(buffer);
    if (char_map == NULL) {
        dprintf(2, "Error: map transform from buffer failed\n");
        return NULL;
    }
    map = char_to_soko(char_map);
    free_str_array(char_map);
    map = fill_sokomap(map, sys);
    return map;
}

sokospot_t ***get_map(char const *filepath, system_t *sys)
{
    char *buffer = get_file_content(filepath);
    char sep[3] = {0};

    if (buffer == NULL) {
        dprintf(2, "Error: unable to get the map array in \"%s\"\n", filepath);
        return NULL;
    }
    sep[0] = END_OF_MAP_LINE;
    sep[1] = '\n';
    sep[2] = '\0';
    return transfrom_map(buffer, sep, sys);
}
