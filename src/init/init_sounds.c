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

void launch_music(parameters_t *param)
{
    if (param->music == NULL) {
        param->music = init_sound(MUSIC_PATH);
        if (param->music == NULL)
            return;
        sfMusic_play(param->music);
    }
}

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
