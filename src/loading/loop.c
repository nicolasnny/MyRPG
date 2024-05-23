/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** Loop for the loading screen
*/

#include "rpg.h"

static bool wait_time(double time_to_wait)
{
    static sfClock *clock = NULL;

    if (clock == NULL) {
        sfClock_create();
        return true;
    }
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) > time_to_wait) {
        sfClock_restart(clock);
        return true;
    }
    return false;
}

static bool move_sprite(sfSprite *s, sfVector2u *win_size)
{
    sfSprite_move(s, (sfVector2f){LOAD_RIGHT_MVT, 0});
    if (get_center(s).x > win_size->x)
        return false;
    return true;
}

static bool move_screen(parameters_t *param)
{
    sfVector2u win_size = sfRenderWindow_getSize(param->window);
    entity_t *e = get_entity_by_name(param->sys, LOAD_MC_NAME);
    static sfIntRect texture_pos =
        (sfIntRect){0, PLAYER_WALK_START, PLAYER_WIDTH, PLAYER_HEIGHT};

    if (e != NULL && wait_time(LOAD_TIME_MOVE)) {
        animate_player_walk(&texture_pos, e->sprite);
        if (!move_sprite(e->sprite, &win_size))
            return true;
        return false;
    }
    return true;
}

static bool load_events(parameters_t *param, bool state)
{
    while (sfRenderWindow_pollEvent(param->window, &param->event)) {
        if (param->event.type == sfEvtKeyPressed) {
            return true;
        }
    }
    return state;
}

int loading_screen_loop(parameters_t *param)
{
    bool load_over = false;

    while (!load_over && sfRenderWindow_isOpen(param->window)) {
        load_over = move_screen(param);
        display_entities(param, LOADING);
        sfRenderWindow_display(param->window);
        mouse_events(param, LOADING);
        load_over = load_events(param, load_over);
        sfRenderWindow_clear(param->window, sfBlack);
    }
    return SUCCESS;
}
