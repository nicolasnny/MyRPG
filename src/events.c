/*
** EPITECH PROJECT, 2024
** MY_RPG
** File description:
** Functions related to events
*/

#include "rpg.h"
#include "struct.h"
#include <SFML/Graphics.h>

int get_p_move_event(parameters_t *param)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        return sfKeyUp;
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        return sfKeyRight;
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        return sfKeyLeft;
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        return sfKeyDown;
    }
    return NO_ARROW_KEY_PRESSED;
}

int analyse_events(parameters_t *param)
{
    if (param->event.type == sfEvtClosed ||
        sfKeyboard_isKeyPressed(sfKeyEscape)) {
        sfRenderWindow_close(param->window);
    }
    return SUCCESS;
}
