/*
** EPITECH PROJECT, 2024
** MY_RPG
** File description:
** Functions related to events
*/

#include "rpg.h"
#include "struct.h"
#include <SFML/Graphics.h>

int analyse_events(parameters_t *param)
{
    if (param->event.type == sfEvtClosed ||
        sfKeyboard_isKeyPressed(sfKeyEscape)) {
        sfRenderWindow_close(param->window);
    }
    move_player(param);
    return SUCCESS;
}
