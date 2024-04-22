/*
** EPITECH PROJECT, 2024
** MY_RPG
** File description:
** Get the array representation of the map from the file
*/

#include <stdlib.h>
#include <stdio.h>
#include "rpg.h"

char **get_map(char const *filepath)
{
    char *buffer = get_file_content(filepath);
    char **map = NULL;
    char sep[3] = {0};

    if (buffer == NULL) {
        dprintf(2, "Error: unable to get the map array in \"%s\"\n", filepath);
        return NULL;
    }
    sep[0] = END_OF_MAP_LINE;
    sep[1] = '\n';
    sep[2] = '\0';
    map = my_pimp_str_to_wa(buffer, sep);
    free(buffer);
    if (map == NULL) {
        dprintf(2, "Error: map transform from buffer failed\n");
        return NULL;
    }
    return map;
}
