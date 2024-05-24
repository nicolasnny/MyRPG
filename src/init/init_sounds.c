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

static void load_sounds_buffers(sounds_effect_t *sounds)
{
    sfSound_setBuffer(sounds->enemy_attack,
        sfSoundBuffer_createFromFile(ENEMY_ATTACK_SOUND));
    sfSound_setBuffer(sounds->player_attack,
        sfSoundBuffer_createFromFile(PLAYER_ATTACK_SOUND));
    sfSound_setBuffer(sounds->player_damage,
        sfSoundBuffer_createFromFile(PLAYER_DAMMAGE_SOUND));
    sfSound_setBuffer(sounds->walk_1,
        sfSoundBuffer_createFromFile(PLAYER_WALK_1));
    sfSound_setBuffer(sounds->walk_2,
        sfSoundBuffer_createFromFile(PLAYER_WALK_2));
    sfSound_setBuffer(sounds->loading,
        sfSoundBuffer_createFromFile(LOADING_SOUND));
    sfSound_setBuffer(sounds->bump,
        sfSoundBuffer_createFromFile(BUMP_SOUND));
    sfSound_setBuffer(sounds->enemy_damage,
        sfSoundBuffer_createFromFile(ENEMY_DAMAGE_SOUND));
}

static void set_sounds_volumes(sounds_effect_t *sounds)
{
    sfSound_setVolume(sounds->enemy_attack, EFFECTS_VOLUME);
    sfSound_setVolume(sounds->player_attack, EFFECTS_VOLUME);
    sfSound_setVolume(sounds->bump, MAX_VOLUME);
    sfSound_setVolume(sounds->player_damage, MAX_VOLUME);
    sfSound_setVolume(sounds->loading, MAX_VOLUME);
    sfSound_setVolume(sounds->walk_1, LOW_VOLUME);
    sfSound_setVolume(sounds->walk_2, LOW_VOLUME);
    sfSound_setVolume(sounds->enemy_damage, MAX_VOLUME);
}

sounds_effect_t *init_sounds_effect(void)
{
    sounds_effect_t *sounds = malloc(sizeof(sounds_effect_t));

    if (sounds == NULL)
        return NULL;
    sounds->enemy_attack = sfSound_create();
    sounds->player_attack = sfSound_create();
    sounds->player_damage = sfSound_create();
    sounds->walk_1 = sfSound_create();
    sounds->walk_2 = sfSound_create();
    sounds->loading = sfSound_create();
    sounds->bump = sfSound_create();
    sounds->enemy_damage = sfSound_create();
    load_sounds_buffers(sounds);
    set_sounds_volumes(sounds);
    return sounds;
}

sfMusic *init_sound(char *path)
{
    sfMusic *music = sfMusic_createFromFile(path);

    if (music == NULL) {
        return NULL;
    }
    sfMusic_setLoop(music, true);
    sfMusic_setVolume(music, MID_VOLUME);
    return music;
}
