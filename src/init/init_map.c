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

static sokospot_t *create_defaut_sokospot(char type)
{
    sokospot_t *spot = malloc(sizeof(sokospot_t));

    if (spot == NULL) {
        perror("init spot malloc failed");
        return NULL;
    }
    spot->type = EMPTY;
    if (type == OBSTACLE)
        spot->type = type;
    return spot;
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

static sokospot_t ***transfrom_map(char *buffer, char *sep)
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
    return map;
}

sokospot_t ***get_map(char const *filepath)
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
    return transfrom_map(buffer, sep);
}
