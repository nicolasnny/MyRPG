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

static bool is_in(sfVector2f *mouse, sfFloatRect *rect)
{
    if (mouse->x <= rect->left + rect->width &&
        mouse->x >= rect->left &&
        mouse->y <= rect->top + rect->height &&
        mouse->y >= rect->top){
        return true;
    }
    return false;
}

static void click_entity(e_list_t *compo_list, parameters_t *param)
{
    e_list_t *temp = compo_list;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(param->window);
    sfVector2u window_pos = sfRenderWindow_getSize(param->window);
    sfVector2f new_pos;
    sfFloatRect e_pos;

    new_pos.x = (mouse_pos.x / (double)window_pos.x) * (double)WIN_WIDTH;
    new_pos.y = (mouse_pos.y / (double)window_pos.y) * (double)WIN_HEIGHT;
    if (!sfMouse_isButtonPressed(sfMouseLeft))
        return;
    while (temp) {
        if (temp->entity->sprite) {
            e_pos = sfSprite_getGlobalBounds(temp->entity->sprite);
        }
        if (!temp->entity->sprite && temp->entity->rect)
            e_pos = sfRectangleShape_getGlobalBounds(temp->entity->rect);
        if (is_in(&new_pos, &e_pos) && temp->entity->clicked)
            temp->entity->clicked(param, temp->entity, true);
        temp = temp->next;
    }
}

static void hover_entity(e_list_t *compo_list, parameters_t *param)
{
    e_list_t *temp = compo_list;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(param->window);
    sfVector2u window_pos = sfRenderWindow_getSize(param->window);
    sfVector2f new_pos;
    sfFloatRect e_pos;

    new_pos.x = (mouse_pos.x / (double)window_pos.x) * (double)WIN_WIDTH;
    new_pos.y = (mouse_pos.y / (double)window_pos.y) * (double)WIN_HEIGHT;
    while (temp) {
        if (temp->entity->sprite) {
            e_pos = sfSprite_getGlobalBounds(temp->entity->sprite);
        }
        if (!temp->entity->sprite && temp->entity->rect)
            e_pos = sfRectangleShape_getGlobalBounds(temp->entity->rect);
        if (is_in(&new_pos, &e_pos) && temp->entity->hovered)
            temp->entity->hovered(param, temp->entity, true);
        if (!is_in(&new_pos, &e_pos) && temp->entity->hovered)
            temp->entity->hovered(param, temp->entity, false);
        temp = temp->next;
    }
}

int mouse_events(parameters_t *param, int component)
{
    e_list_t *compo_list = get_entities(param->sys, component);

    while (sfRenderWindow_pollEvent(param->window, &param->event)) {
        if (param->event.type == sfEvtClosed) {
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
        if (param->event.type == sfEvtClosed) {
            sfRenderWindow_close(param->window);
        }
        if (param->event.type == sfEvtKeyPressed)
            change_selected_item(param->sys);
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            in_game_menu(param);
        }
        if (sfKeyboard_isKeyPressed(sfKeyA)) {
            get_item(param);
        }
        if (sfKeyboard_isKeyPressed(sfKeyE)) {
            drop_selected_item(param->sys);
        }
    }
    return SUCCESS;
}
