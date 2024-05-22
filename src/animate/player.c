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

void animate_player_walk(sfIntRect *texture_pos, sfSprite *player)
{
    if (is_spaced(REFRESH_SPEED_WALK))
        texture_pos->left += PLAYER_WIDTH;
    if (texture_pos->left >= MAX_WALK_TEXTURE)
        texture_pos->left = 0;
    sfSprite_setTextureRect(player, *texture_pos);
}

void annimate_idle(sfIntRect *idle_pos, sfSprite *player)
{
    if (is_spaced(REFRESH_SPEED_IDLE))
        idle_pos->top += PLAYER_WIDTH;
    if (idle_pos->top >= MAX_IDLE_TEXTURE)
        idle_pos->top = PLAYER_IDLE_START;
    sfSprite_setTextureRect(player, *idle_pos);
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
