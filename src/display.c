/*
** EPITECH PROJECT, 2023
** MY_RADAR
** File description:
** Functions related to the displaying
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <stdio.h>
#include <string.h>
#include "rpg.h"

static bool disp_box(parameters_t *param)
{
    e_list_t *is_box = get_entities(param->sys, BOX);

    while (is_box) {
        if (is_box->entity->text)
            sfRenderWindow_drawText(param->window, is_box->entity->text, NULL);
        is_box = is_box->next;
    }
    return true;
}

void display_entities(parameters_t *param, int component)
{
    e_list_t *list = get_entities(param->sys, component);
    e_list_t *head = NULL;

    head = list;
    while (list != NULL) {
        if (list->entity->sprite)
            sfRenderWindow_drawSprite(param->window,
            list->entity->sprite, NULL);
        if (list->entity->rect)
            sfRenderWindow_drawRectangleShape(param->window,
            list->entity->rect, NULL);
        if (list->entity->text)
            sfRenderWindow_drawText(param->window, list->entity->text, NULL);
        list = list->next;
    }
    disp_box(param);
    clean_list(head);
}
