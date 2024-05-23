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

sfVector2f get_view_pos(sfView *v)
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
    sfVector2f *view_size, sfVector2f *last_pos)
{
    sfFloatRect s_size = sfSprite_getGlobalBounds(s);
    sfVector2f pos = *last_pos;

    pos.x = view_pos->x + view_size->x * pos.x / WIN_WIDTH - s_size.width / 2;
    pos.y = view_pos->y + view_size->y * pos.y / WIN_HEIGHT
    - s_size.height / 2;
    return pos;
}

static void set_ingame_pos(sfVector2f *s_pos, entity_t *entity,
    sfVector2f *view_pos, sfVector2f *view_size)
{
    if (entity->name && strcmp(entity->name, "map") != 0) {
        *s_pos = get_sprite_real_pos(entity->sprite, view_pos,
        view_size, &(entity->pos));
        sfSprite_setPosition(entity->sprite, *s_pos);
    }
}

static void set_ingame_sprite_pos(parameters_t *param)
{
    e_list_t *menu = get_entities(param->sys, IN_GAME_MENU);
    e_list_t *temp = menu;
    sfVector2f view_pos = get_view_pos(param->view);
    sfVector2f s_pos = {0};
    sfVector2f view_size = sfView_getSize(param->view);

    sfView_zoom(param->view, MENU_UNZOOM);
    sfRenderWindow_setView(param->window, param->view);
    while (temp) {
        if (temp->entity->name && strcmp(temp->entity->name, "map") != 0
            && temp->entity->pos.x == NEG_ERROR) {
            s_pos = sfSprite_getPosition(temp->entity->sprite);
            temp->entity->pos = s_pos;
        }
        set_ingame_pos(&s_pos, temp->entity, &view_pos, &view_size);
        temp = temp->next;
    }
    clean_list(menu);
}

void in_game_menu(parameters_t *param)
{
    e_list_t *compo_list = get_entities(param->sys, IN_GAME_MENU);
    e_list_t *temp = compo_list;

    set_ingame_sprite_pos(param);
    param->game_state = PAUSE;
    while (param->game_state == PAUSE &&
        sfRenderWindow_isOpen(param->window)) {
        display_entities(param, IN_GAME_MENU);
        sfRenderWindow_display(param->window);
        mouse_events(param, IN_GAME_MENU, temp);
        sfRenderWindow_clear(param->window, sfBlack);
    }
    if (param->view)
        sfView_zoom(param->view, MENU_ZOOM);
    if (sfRenderWindow_isOpen(param->window))
        sfRenderWindow_setView(param->window, param->view);
    clean_list(compo_list);
}
