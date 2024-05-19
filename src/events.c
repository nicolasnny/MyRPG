/*
** EPITECH PROJECT, 2024
** MY_RPG
** File description:
** Functions related to events
*/

#include <SFML/Graphics.h>
#include "rpg.h"
#include "struct.h"

int analyse_events(parameters_t *param)
{
    while (sfRenderWindow_pollEvent(param->window, &param->event)) {
        if (param->event.type == sfEvtClosed ||
            sfKeyboard_isKeyPressed(sfKeyEscape)) {
            sfRenderWindow_close(param->window);
        }
        if (param->event.type == sfEvtKeyPressed) {
            move_player(param);
            change_selected_item(param->sys);
        }
    }
    return SUCCESS;
}
