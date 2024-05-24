/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-nicolas.nunney
** File description:
** volume.c
*/

#include "rpg.h"
#include "struct.h"
#include "associative.h"

int set_sound_volume_down(parameters_t *param, entity_t *entity, bool state)
{
    sfSound_setVolume(param->sounds_effect->enemy_attack,
        sfSound_getVolume(param->sounds_effect->enemy_attack) - 10);
    sfSound_setVolume(param->sounds_effect->player_attack,
        sfSound_getVolume(param->sounds_effect->player_attack) - 10);
    sfSound_setVolume(param->sounds_effect->bump,
        sfSound_getVolume(param->sounds_effect->bump) - 10);
    sfSound_setVolume(param->sounds_effect->player_damage,
        sfSound_getVolume(param->sounds_effect->player_damage) - 10);
    sfSound_setVolume(param->sounds_effect->loading,
        sfSound_getVolume(param->sounds_effect->loading) - 10);
    sfSound_setVolume(param->sounds_effect->walk_1,
        sfSound_getVolume(param->sounds_effect->walk_1) - 10);
    sfSound_setVolume(param->sounds_effect->walk_2,
        sfSound_getVolume(param->sounds_effect->walk_2) - 10);
    sfSound_setVolume(param->sounds_effect->enemy_damage,
        sfSound_getVolume(param->sounds_effect->enemy_damage) - 10);
    (void)entity;
    (void)state;
    return SUCCESS;
}

int set_sound_volume_up(parameters_t *param, entity_t *entity, bool state)
{
    sfSound_setVolume(param->sounds_effect->enemy_attack,
        sfSound_getVolume(param->sounds_effect->enemy_attack) + 10);
    sfSound_setVolume(param->sounds_effect->player_attack,
        sfSound_getVolume(param->sounds_effect->player_attack) + 10);
    sfSound_setVolume(param->sounds_effect->bump,
        sfSound_getVolume(param->sounds_effect->bump) + 10);
    sfSound_setVolume(param->sounds_effect->player_damage,
        sfSound_getVolume(param->sounds_effect->player_damage) + 10);
    sfSound_setVolume(param->sounds_effect->loading,
        sfSound_getVolume(param->sounds_effect->loading) + 10);
    sfSound_setVolume(param->sounds_effect->walk_1,
        sfSound_getVolume(param->sounds_effect->walk_1) + 10);
    sfSound_setVolume(param->sounds_effect->walk_2,
        sfSound_getVolume(param->sounds_effect->walk_2) + 10);
    sfSound_setVolume(param->sounds_effect->enemy_damage,
        sfSound_getVolume(param->sounds_effect->enemy_damage) + 10);
    (void)entity;
    (void)state;
    return SUCCESS;
}

int reset_sound_volume(parameters_t *param, entity_t *entity, bool state)
{
    param->sound_volume = DEFAULT_VOLUME;
    (void)entity;
    (void)state;
    return SUCCESS;
}
