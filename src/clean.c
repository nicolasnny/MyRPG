/*
** EPITECH PROJECT, 2023
** MY_RADAR
** File description:
** Functions to clean my radar
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "rpg.h"

void free_str_array(char **array)
{
    for (unsigned int i = 0; array[i]; i++) {
        free(array[i]);
    }
    free(array);
}

void clean(parameters_t *param)
{
    if (param->map_array != NULL) {
        free_str_array(param->map_array);
    }
}
