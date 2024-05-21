/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-nicolas.nunney
** File description:
** in_game_menu.c
*/

#include <string.h>
#include "rpg.h"
#include "struct.h"
#include "associative.h"

static sfVector2f get_view_pos(sfView *v)
{
    sfVector2f pos = {0};
    sfVector2f center = {0};
    sfVector2f size = {0};

    if (v == NULL) {
        return pos;
    }
    center = sfView_getCenter(v);
    size = sfView_getSize(v);
    pos.x = center.x - size.x / 2;
    pos.y = center.y - size.y / 2;
    return pos;
}

static sfVector2f get_sprite_real_pos(sfSprite *s, sfVector2f *view_pos,
    sfVector2f *view_size)
{
    sfFloatRect s_size = sfSprite_getGlobalBounds(s);
    sfVector2f pos = sfSprite_getPosition(s);

    pos.x = view_pos->x + view_size->x * pos.x / WIN_WIDTH - s_size.width / 2;
    pos.y = view_pos->y + view_size->y * pos.y / WIN_HEIGHT - s_size.height / 2;
    return pos;
}

static void set_sprite_pos(parameters_t *param)
{
    e_list_t *menu = get_entities(param->sys, IN_GAME_MENU);
    sfVector2f view_pos = get_view_pos(param->view);
    sfVector2f s_pos = {0};
    sfVector2f view_size = sfView_getSize(param->view);

    sfView_zoom(param->view, MENU_UNZOOM);
    sfRenderWindow_setView(param->window, param->view);
    while (menu) {
        if (menu->entity->name && strcmp(menu->entity->name, "map") != 0) {
            s_pos = get_sprite_real_pos(menu->entity->sprite, &view_pos, &view_size);
            sfSprite_setPosition(menu->entity->sprite, s_pos);
            // offset += MENU_OFFSET;
        }
        menu = menu->next;
    }
}

void in_game_menu(parameters_t *param)
{
    set_sprite_pos(param);
    param->game_state = PAUSE;
    sfFloatRect rect = {0};

    while (param->game_state == PAUSE) {
        sfVector2i m_pos = sfMouse_getPositionRenderWindow(param->window);
        sfVector2u window_pos = sfRenderWindow_getSize(param->window);
        printf("mouse pos: {%f, %f}\n", (m_pos.x / (double)window_pos.x) * (double)WIN_WIDTH, (m_pos.y / (double)window_pos.y) * (double)WIN_HEIGHT);
        entity_t *tmp = get_entity_by_name(param->sys, "quit");
        if (tmp)
            rect = sfSprite_getGlobalBounds(tmp->sprite);
        printf("qui button => pos {%f, %f}, width: %f, height: %f\n" , rect.left, rect.top, rect.width, rect.height);
        display_entities(param, IN_GAME_MENU);
        sfRenderWindow_display(param->window);
        mouse_events(param, IN_GAME_MENU);
        sfRenderWindow_clear(param->window, sfBlack);
    }
    sfView_zoom(param->view, 0.66666666666667);
    sfRenderWindow_setView(param->window, param->view);
}
