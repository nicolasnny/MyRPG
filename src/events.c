/*
** EPITECH PROJECT, 2024
** MY_RPG
** File description:
** Functions related to events
*/

#include <SFML/Graphics.h>
#include "rpg.h"
#include "struct.h"

bool is_in(sfVector2i *mouse, sfFloatRect *rect)
{
    if (mouse->x <= rect->left + rect->width && mouse->x >= rect->left &&
        mouse->y <= rect->top + rect->height && mouse->y >= rect->top){
        return true;
    }
    return false;
}

static void click_entity(e_list_t *compo_list, parameters_t *param)
{
    e_list_t *temp = compo_list;
    sfVector2i mouse_pos = sfMouse_getPosition((sfWindow *)param->window);
    sfFloatRect sprite_pos;

    while (temp) {
        sprite_pos = sfSprite_getGlobalBounds(temp->entity->sprite);
        if (is_in(&mouse_pos, &sprite_pos) && temp->entity->clicked) {
            temp->entity->clicked(param, param->sys, temp->entity);
        }
        temp = temp->next;
    }
}

static void hover_entity(e_list_t *compo_list, parameters_t *param)
{
    e_list_t *temp = compo_list;
    sfVector2i mouse_pos = sfMouse_getPosition((sfWindow *)param->window);
    sfFloatRect sprite_pos;

    while (temp) {
        sprite_pos = sfSprite_getGlobalBounds(temp->entity->sprite);
        if (is_in(&mouse_pos, &sprite_pos) && temp->entity->hovered) {
            temp->entity->hovered(param, param->sys, temp->entity);
        }
        temp = temp->next;
    }
}

int mouse_events(parameters_t *param, int component)
{
    e_list_t *compo_list = get_entities(param->sys, component);

    while (sfRenderWindow_pollEvent(param->window, &param->event)) {
        if (param->event.type == sfEvtClosed ||
            sfKeyboard_isKeyPressed(sfKeyEscape)) {
            sfRenderWindow_close(param->window);
        }
        hover_entity(compo_list, param);
        if (param->event.type == sfEvtMouseButtonPressed) {
            click_entity(compo_list, param);
        }
    }
    return SUCCESS;
}

int window_events(parameters_t *param)
{
    while (sfRenderWindow_pollEvent(param->window, &param->event)) {
        if (param->event.type == sfEvtClosed ||
            sfKeyboard_isKeyPressed(sfKeyEscape)) {
            sfRenderWindow_close(param->window);
        }
        if (param->event.type == sfEvtKeyPressed) {
            move_player(param);
        }
    }
    return SUCCESS;
}
