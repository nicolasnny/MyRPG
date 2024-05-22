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

void make_life(parameters_t *param)
{
    if (time_move_mobs(TIME_BEFORE_MOBS_MOVE))
        move_mobs(param, param->map_array);
    check_player_collisions(param->sys);
}
