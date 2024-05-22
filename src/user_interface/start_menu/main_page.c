/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-nicolas.nunney
** File description:
** main_page.c
*/

#include <stdio.h>
#include <stdbool.h>
#include "rpg.h"
#include "struct.h"

int start_menu(parameters_t *param, entity_t *entity, bool state)
{

    (void)entity;
    (void)state;
    if (param->music == NULL) {
        param->music = init_sound(MUSIC_PATH);
        sfMusic_play(param->music);
    }
    if (param->music == NULL)
        return ERROR;
    destroy_view(param);
    while (sfRenderWindow_isOpen(param->window) &&
        param->game_state == PAUSE) {
        display_entities(param, MENU);
        sfRenderWindow_display(param->window);
        mouse_events(param, CLICKABLE);
        sfRenderWindow_clear(param->window, sfBlack);
    }
    if (!sfRenderWindow_isOpen(param->window))
        return ERROR;
    reset_view(param);
    return SUCCESS;
}
