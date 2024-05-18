/*
** EPITECH PROJECT, 2024
** MY_RPG
** File description:
** Functions related to events
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "rpg.h"
#include "struct.h"

bool is_in(sfVector2f *mouse, sfFloatRect *rect, sfVector2u *window_pos)
{
    sfFloatRect scaled_rect;

    scaled_rect.left = (rect->left / (double)WIN_WIDTH) * window_pos->x;
    scaled_rect.top = (rect->top / (double)WIN_HEIGHT) * window_pos->y;
    scaled_rect.width = (rect->width / (double)WIN_WIDTH) * window_pos->x;
    scaled_rect.height = (rect->height / (double)WIN_HEIGHT) * window_pos->y;
    if (mouse->x <= scaled_rect.left + scaled_rect.width &&
        mouse->x >= scaled_rect.left &&
        mouse->y <= scaled_rect.top + scaled_rect.height &&
        mouse->y >= scaled_rect.top){
        return true;
    }
    return false;
}

static void click_entity(e_list_t *compo_list, parameters_t *param)
{
    e_list_t *temp = compo_list;
    sfVector2i mouse_pos = sfMouse_getPosition((sfWindow *)param->window);
    sfVector2u window_pos = sfRenderWindow_getSize(param->window);
    sfVector2f new_pos;
    sfFloatRect e_pos;

    new_pos.x = (mouse_pos.x / (double)WIN_WIDTH) * (double)window_pos.x;
    new_pos.y = (mouse_pos.y / (double)WIN_HEIGHT) * (double)window_pos.y;
    if (!sfMouse_isButtonPressed(sfMouseLeft))
        return;
    while (temp) {
        if (temp->entity->sprite)
            e_pos = sfSprite_getGlobalBounds(temp->entity->sprite);
        if (!temp->entity->sprite && temp->entity->rect)
            e_pos = sfRectangleShape_getGlobalBounds(temp->entity->rect);
        if (is_in(&new_pos, &e_pos, &window_pos) && temp->entity->clicked)
            temp->entity->clicked(param, temp->entity, true);
        temp = temp->next;
    }
}

static void hover_entity(e_list_t *compo_list, parameters_t *param)
{
    e_list_t *temp = compo_list;
    sfVector2i mouse_pos = sfMouse_getPosition((sfWindow *)param->window);
    sfVector2u window_pos = sfRenderWindow_getSize(param->window);
    sfVector2f new_pos;
    sfFloatRect e_pos;

    new_pos.x = (mouse_pos.x / (double)WIN_WIDTH) * (double)window_pos.x;
    new_pos.y = (mouse_pos.y / (double)WIN_HEIGHT) * (double)window_pos.y;
    while (temp) {
        if (temp->entity->sprite)
            e_pos = sfSprite_getGlobalBounds(temp->entity->sprite);
        if (!temp->entity->sprite && temp->entity->rect)
            e_pos = sfRectangleShape_getGlobalBounds(temp->entity->rect);
        if (is_in(&new_pos, &e_pos, &window_pos) && temp->entity->hovered)
            temp->entity->hovered(param, temp->entity, true);
        if (!is_in(&new_pos, &e_pos, &window_pos) && temp->entity->hovered)
            temp->entity->hovered(param, temp->entity, false);
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
            exit(0);
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
