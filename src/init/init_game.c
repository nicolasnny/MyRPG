/*
** EPITECH PROJECT, 2024
** MY_RPG
** File description:
** Functions related to my_rpg initialinisation
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include "rpg.h"

sfView *create_view(void)
{
    sfView *view = sfView_create();

    if (view == NULL) {
        dprintf(2, "Error: view initialisation failed\n");
        return NULL;
    }
    return view;
}

sounds_effect_t *init_sounds_effect(void)
{
    sounds_effect_t *sounds = malloc(sizeof(sounds_effect_t));

    if (sounds == NULL) {
        perror("systemp malloc failed");
        return NULL;
    }
    sounds->enemy_attack = sfSound_create();
    sounds->player_attack = sfSound_create();
    sounds->player_damage = sfSound_create();
    sfSound_setBuffer(sounds->enemy_attack,
        sfSoundBuffer_createFromFile(ENEMY_ATTACK_SOUND));
    sfSound_setBuffer(sounds->player_attack,
        sfSoundBuffer_createFromFile(PLAYER_ATTACK_SOUND));
    sfSound_setBuffer(sounds->player_damage,
        sfSoundBuffer_createFromFile(PLAYER_DAMMAGE_SOUND));
    sfSound_setVolume(sounds->enemy_attack, MAX_VOLUME);
    sfSound_setVolume(sounds->player_attack, MAX_VOLUME);
    sfSound_setVolume(sounds->player_damage, MAX_VOLUME);
    return sounds;
}

int init_args(parameters_t *param)
{
    sfVideoMode video_mode = {WIN_WIDTH, WIN_HEIGHT, WIN_PIX_NB};

    param->clock = sfClock_create();
    param->window = sfRenderWindow_create(video_mode, "My RPG",
        sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(param->window, FPS);
    param->sys = create_system();
    if (param->sys == NULL || param->window == NULL || param->clock == NULL) {
        return ERROR;
    }
    create_from_conf(param);
    param->map_array = get_map(MAP_ARRAY_PATH);
    if (param->map_array == NULL)
        return ERROR;
    param->game_state = PAUSE;
    param->view = create_view();
    param->sound_volume = 100.0;
    param->music = NULL;
    param->sounds_effect = init_sounds_effect();
    return SUCCESS;
}
