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
    return SUCCESS;
}

int set_1920x1080(parameters_t *param, entity_t *entity, bool state)
{
    (void)entity;
    (void)state;
    sfRenderWindow_setSize(param->window, (sfVector2u){1920, 1080});
    return SUCCESS;
}

int options_menu(parameters_t *param, entity_t *entity, bool state)
{
    e_list_t *compo_list = get_entities(param->sys, SETTINGS);
    e_list_t *temp = compo_list;

    (void)entity;
    (void)state;
    destroy_view(param);
    while (param->game_state == PAUSE) {
        display_entities(param, SETTINGS);
        sfRenderWindow_display(param->window);
        mouse_events(param, SETTINGS, temp);
        sfRenderWindow_clear(param->window, sfBlack);
    }
    reset_view(param);
    clean_list(compo_list);
    return true;
}
