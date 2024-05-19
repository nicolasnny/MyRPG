/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-nicolas.nunney
** File description:
** options.c
*/

#include "rpg.h"
#include "struct.h"

int set_2560x1600(parameters_t *param, entity_t *entity, bool state)
{
    (void)entity;
    (void)state;
    sfRenderWindow_setSize(param->window, (sfVector2u){2560, 1600});
    reset_view(param->window, param->view);
    return SUCCESS;
}

int set_1920x1080(parameters_t *param, entity_t *entity, bool state)
{
    (void)entity;
    (void)state;
    sfRenderWindow_setSize(param->window, (sfVector2u){1920, 1080});
    reset_view(param->window, param->view);
    return SUCCESS;
}

int options_menu(parameters_t *param, entity_t *entity, bool state)
{
    (void)entity;
    (void)state;
    reset_view(param->window, param->view);
    while (param->game_state == PAUSE) {
        display_entities(param, SETTINGS);
        sfRenderWindow_display(param->window);
        mouse_events(param, SETTINGS);
        sfRenderWindow_clear(param->window, sfBlack);
    }
    return true;
}
