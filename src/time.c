/*
** EPITECH PROJECT, 2023
** MY_RADAR
** File description:
** Functions related to the time
*/

#include <SFML/Graphics.h>
#include <stdbool.h>

bool wait_time(sfClock *clock, float time_sleep)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = time.microseconds / 1000000.0;

    if (seconds > time_sleep) {
        sfClock_restart(clock);
        return true;
    }
    return false;
}
