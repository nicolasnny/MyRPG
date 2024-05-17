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

static sokospot_t *init_spot(entity_t *e, char type)
{
    sokospot_t *spot = malloc(sizeof(sokospot_t));

    if (spot == NULL) {
        perror("init spot malloc failed");
        return NULL;
    }
    spot->entity = e;
    spot->type = type;
    spot->moved_in_frame = false;
    return spot;
}

static sokospot_t *create_sokospot(char type, system_t *sys)
{
    if (type == OBSTACLE || type == NPC_LIMIT || type == EMPTY) {
        return init_spot(NULL, type);
    }
    if (type == PLAYER_CHAR) {
        return init_spot(create_entity(sys, PLAYER_SPRITE_PATH,
        NULL, VISIBLE | PLAYER), type);
    }
    if (type == ENEMY) {
        return init_spot(create_entity
        (sys, MOB_SPRITE_PATH, NULL, VISIBLE | MOB), type);
    }
    return init_spot(create_entity
    (sys, NPC_SPRITE_PATH, NULL, VISIBLE | NPC), type);
}

static sokospot_t ***char_to_soko(char **char_map, system_t *sys)
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
            map[line][col] = create_sokospot(char_map[line][col], sys);
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
    map = char_to_soko(char_map, sys);
    free_str_array(char_map);
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
