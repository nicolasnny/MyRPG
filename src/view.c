/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-nicolas.nunney
** File description:
** view.c
*/

#include "rpg.h"
#include "associative.h"
#include "struct.h"

void reset_view(sfRenderWindow *window, sfView *view)
{
    sfVector2u windowSize = sfRenderWindow_getSize(window);
    sfVector2f center = {windowSize.x / 2.0, windowSize.y / 2.0};
    sfVector2f size = {windowSize.x, windowSize.y};
    sfFloatRect viewport = {0.0, 0.0, 1.0, 1.0};

    sfView_setCenter(view, center);
    sfView_setSize(view, size);
    sfView_setViewport(view, viewport);
    sfRenderWindow_setView(window, view);
}

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
