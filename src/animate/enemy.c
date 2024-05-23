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
    sfIntRect current = sfSprite_getTextureRect(enemy->sprite);
    sfInt32 time = (sfTime_asMilliseconds(sfClock_getElapsedTime(param->clock)) -
        sfTime_asMilliseconds(enemy->entity_time));

    current.top = ENEMY_WALK_START;
    if (time >= ENEMY_REFRESH_SPEED_WALK) {
        current.left += ENEMY_WIDTH * 2;
        enemy->entity_time = sfClock_getElapsedTime(param->clock);
    }
    if (current.left >= ENEMY_MAX_WALK_TEXTURE)
        current.left = 0;
    sfSprite_setTextureRect(enemy->sprite, current);
}

void anime_enemy_fight(parameters_t *param, entity_t *enemy)
{
    sfIntRect current = sfSprite_getTextureRect(enemy->sprite);
    sfInt32 time = (sfTime_asMilliseconds(sfClock_getElapsedTime(param->clock)) -
        sfTime_asMilliseconds(enemy->entity_time));

    printf("Yup %s\n", enemy->name);
    current.top = ENEMY_ATTACK_START;
    if (time >= ENEMY_REFRESH_SPEED_WALK) {
        current.left += ENEMY_WIDTH * 2;
        enemy->entity_time = sfClock_getElapsedTime(param->clock);
    }
    if (current.left >= ENEMY_MAX_ATTACK_TEXTURE) {
        sfSound_play(param->sounds_effect->enemy_attack);
        current.left = 0;
    }
    sfSprite_setTextureRect(enemy->sprite, current);
}
