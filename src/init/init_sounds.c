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

sfSound *init_sound(char *path)
{
    sfSound *sound = sfSound_create();
    sfSoundBuffer *sound_buffer = sfSoundBuffer_createFromFile(path);

    if (sound == NULL || sound_buffer == NULL) {
        return NULL;
    }
    sfSound_setBuffer(sound, sound_buffer);
    sfSound_setVolume(sound, 100);
    return sound;
}
