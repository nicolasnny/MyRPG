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

sfMusic *init_sound(char *path)
{
    sfMusic *music = sfMusic_createFromFile(path);

    if (music == NULL) {
        return NULL;
    }
    sfMusic_setLoop(music, true);
    sfMusic_setVolume(music, 100);
    return music;
}
