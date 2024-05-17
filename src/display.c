/*
** EPITECH PROJECT, 2023
** MY_RADAR
** File description:
** Functions related to the displaying
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include "rpg.h"

void display_entities(parameters_t *param, int component)
{
    e_list_t *list = get_entities(param->sys, component);
    e_list_t *head = NULL;

    reverse_list(&list);
    head = list;
    while (list != NULL) {
        if (list->entity->sprite) {
            sfRenderWindow_drawSprite(param->window,
            list->entity->sprite, NULL);
        }
        if (list->entity->rect) {
            sfRenderWindow_drawRectangleShape(param->window,
            list->entity->rect, NULL);
        }
        list = list->next;
    }
    clean_list(head);
}
