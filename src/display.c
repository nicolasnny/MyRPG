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

void display_sprites(parameters_t *param)
{
    e_list_t *list = get_entities(param->sys, VISIBLE);

    while (list != NULL) {
        sfRenderWindow_drawSprite(param->window, list->entity->sprite, NULL);
    }
    clean_list(list);
}
