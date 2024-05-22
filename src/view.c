/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-nicolas.nunney
** File description:
** view.c
*/

#include <stdio.h>
#include "rpg.h"
#include "associative.h"
#include "struct.h"


void set_view_on_player(parameters_t *param)
{
    e_list_t *p_list = get_entities(param->sys, PLAYER);
    sfSprite *player = NULL;

    if (!p_list)
        return;
    player = p_list->entity->sprite;
    sfView_setCenter(param->view, get_center(player));
    clean_list(p_list);
    sfRenderWindow_setView(param->window, param->view);
}

void destroy_view(parameters_t *param)
{
    const sfView *def = sfRenderWindow_getDefaultView(param->window);

    if (param->view) {
        sfView_destroy(param->view);
        param->view = NULL;
        sfRenderWindow_setView(param->window, def);
    }
}

void reset_view(parameters_t *param)
{
    param->view = create_view();

    set_view_on_player(param);
}