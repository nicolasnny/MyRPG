/*
** EPITECH PROJECT, 2024
** MY_RPG
** File description:
** Functions related to player annimation
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include "rpg.h"
#include "struct.h"

static bool frame_is_spaced(float time_sleep)
{
    static sfClock *clock = NULL;

    if (clock == NULL) {
        clock = sfClock_create();
        return true;
    }
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock))
            > time_sleep) {
        sfClock_restart(clock);
        return true;
    }
    return false;
}

void anime_enemy_walk(parameters_t *param, entity_t *enemy)
{
    if (enemy == NULL)
        return;
    sfIntRect current = sfSprite_getTextureRect(enemy->sprite);
    sfInt32 time = sfClock_getElapsedTime(param->clock).microseconds - enemy->entity_time.microseconds;

    if (time < REFRESH_SPEED_WALK)
        current.left += ENEMY_WIDTH + 8;
    else
        enemy->entity_time = sfClock_getElapsedTime(param->clock);
    if (current.left >= ENEMY_MAX_WALK_TEXTURE)
        current.left = 0;
    sfSprite_setTextureRect(enemy->sprite, current);
}
