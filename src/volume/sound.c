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
    if (param->sound_volume > MIN_VOLUME)
        param->sound_volume--;
    (void)entity;
    (void)state;
    return SUCCESS;
}

int set_sound_volume_up(parameters_t *param, entity_t *entity, bool state)
{
    if (param->sound_volume < MAX_VOLUME)
        param->sound_volume++;
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
