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

static sfVector2f get_menu_pos(sfRenderWindow *win)
{
    sfVector2f new_pos = {0};
    sfVector2u win_size = sfRenderWindow_getSize(win);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(win);

    new_pos.x = (mouse_pos.x / (double)win_size.x) * (double)WIN_WIDTH;
    new_pos.y = (mouse_pos.y / (double)win_size.y) * (double)WIN_HEIGHT;
    return new_pos;
}

static sfVector2f get_mouse_pos(parameters_t *param)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(param->window);
    sfVector2f view_size = sfView_getSize(param->view);
    sfVector2u win_size = sfRenderWindow_getSize(param->window);
    sfVector2f view_pos = get_view_pos(param->view);
    sfVector2f new_pos = {0};

    new_pos.x = view_pos.x + (double)mouse_pos.x / win_size.x * view_size.x;
    new_pos.y = view_pos.y + (double)mouse_pos.y / win_size.y * view_size.y;
    return new_pos;
}

static void click_entity(e_list_t *compo_list, parameters_t *param,
    int component)
{
    e_list_t *temp = compo_list;
    sfFloatRect e_pos = {0};
    sfVector2f m_pos = {0};

    if (!sfMouse_isButtonPressed(sfMouseLeft))
        return;
    if (component == CLICKABLE || component == SETTINGS)
        m_pos = get_menu_pos(param->window);
    else
        m_pos = get_mouse_pos(param);
    while (temp) {
        if (temp->entity->sprite) {
            e_pos = sfSprite_getGlobalBounds(temp->entity->sprite);
        }
        if (!temp->entity->sprite && temp->entity->rect)
            e_pos = sfRectangleShape_getGlobalBounds(temp->entity->rect);
        if (is_in(&m_pos, &e_pos) && temp->entity->clicked)
            temp->entity->clicked(param, temp->entity, true);
        temp = temp->next;
    }
}

static void hover_entity(e_list_t *compo_list, parameters_t *param,
    int component)
{
    e_list_t *temp = compo_list;
    sfFloatRect e_pos = {0};
    sfVector2f m_pos = {0};

    if (component == CLICKABLE || component == SETTINGS)
        m_pos = get_menu_pos(param->window);
    else
        m_pos = get_mouse_pos(param);
    while (temp) {
        if (temp->entity && temp->entity->sprite) {
            e_pos = sfSprite_getGlobalBounds(temp->entity->sprite);
        }
        if (!temp->entity->sprite && temp->entity->rect)
            e_pos = sfRectangleShape_getGlobalBounds(temp->entity->rect);
        if (is_in(&m_pos, &e_pos) && temp->entity->hovered)
            temp->entity->hovered(param, temp->entity, true);
        if (!is_in(&m_pos, &e_pos) && temp->entity->hovered)
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
            param->game_state = QUIT;
        }
        if (param->event.type == sfEvtMouseMoved)
            hover_entity(compo_list, param, component);
        if (param->event.type == sfEvtMouseButtonPressed) {
            click_entity(compo_list, param, component);
        }
    }
    return SUCCESS;
}

int window_events(parameters_t *param, int component)
{
    e_list_t *compo_list = get_entities(param->sys, component);

    while (sfRenderWindow_pollEvent(param->window, &param->event)) {
        mouse_events(param, MOB);
        change_selected_item(param->sys);
        grab_drop_events(param);
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            in_game_menu(param);
        }
        hover_entity(compo_list, param, component);
        if (param->event.type == sfEvtMouseButtonPressed) {
            click_entity(compo_list, param, component);
        }
        if (param->event.type == sfEvtClosed) {
            sfRenderWindow_close(param->window);
        }
    }
    return SUCCESS;
}
