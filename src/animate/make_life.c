/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** Function to trigger game events
*/

#include <SFML/Graphics.h>
#include "rpg.h"

static bool time_move_mobs(float time_sleep)
{
    static sfClock *clock = NULL;

    if (clock == NULL) {
        clock = sfClock_create();
        return true;
    }
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) > time_sleep) {
        sfClock_restart(clock);
        return true;
    }
    return false;
}

static bool time_move_player(float time_sleep)
{
    static sfClock *clock = NULL;

    if (clock == NULL) {
        clock = sfClock_create();
        return true;
    }
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) > time_sleep) {
        sfClock_restart(clock);
        return true;
    }
    return false;
}

void make_life(parameters_t *param)
{
    static sfIntRect texture_pos =
        (sfIntRect){0, PLAYER_WALK_START, PLAYER_WIDTH, PLAYER_HEIGHT};
    static sfIntRect idle_pos =
        (sfIntRect){0, PLAYER_IDLE_START, PLAYER_WIDTH, PLAYER_HEIGHT};
    static sfVector2f scale = (sfVector2f){1, 1};

    if (time_move_mobs(TIME_BEFORE_MOVE))
        move_mobs(param, param->map_array);
    if (time_move_player(TIME_BEFORE_MOVE))
        move_player(param, &texture_pos, &idle_pos, &scale);
    check_player_collisions(param);
}
