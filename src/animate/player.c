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

static bool is_spaced(float time_sleep)
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

void animate_player(sfIntRect *texture_pos)
{
    if (is_spaced(70))
        texture_pos->left += 40;
    if (texture_pos->left >= 140)
        texture_pos->left = 0;
}

void flip_sprite
(sfVector2f *move_save, sfVector2f move, sfSprite *player, sfVector2f *scale)
{
    if (move_save->x == 0 && move_save->y == 0) {
        move_save->x = move.x;
        move_save->y = move.y;
    }
    if ((move.x > 0.0 && move_save->x != move.x) ||
            (move.x < 0.0 && move_save->x != move.x)) {
            scale->x = -1;
            move_save->x = move.x;
            sfSprite_scale(player, *scale);
    }
}
