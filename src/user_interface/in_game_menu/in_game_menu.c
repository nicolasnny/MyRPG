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

static void set_ingame_sprite_pos(parameters_t *param)
{
    e_list_t *menu = get_entities(param->sys, IN_GAME_MENU);
    sfVector2f view_pos = get_view_pos(param->view);
    sfVector2f s_pos = {0};
    sfVector2f view_size = sfView_getSize(param->view);

    sfView_zoom(param->view, MENU_UNZOOM);
    sfRenderWindow_setView(param->window, param->view);
    while (menu) {
        if (menu->entity->name && strcmp(menu->entity->name, "map") != 0
            && menu->entity->pos.x == NEG_ERROR) {
            s_pos = sfSprite_getPosition(menu->entity->sprite);
            menu->entity->pos = s_pos;
        }
        if (menu->entity->name && strcmp(menu->entity->name, "map") != 0) {
            s_pos = get_sprite_real_pos(menu->entity->sprite, &view_pos,
            &view_size, &(menu->entity->pos));
            sfSprite_setPosition(menu->entity->sprite, s_pos);
        }
        menu = menu->next;
    }
}

void in_game_menu(parameters_t *param)
{
    set_ingame_sprite_pos(param);
    param->game_state = PAUSE;
    while (param->game_state == PAUSE &&
        sfRenderWindow_isOpen(param->window)) {
        display_entities(param, IN_GAME_MENU);
        sfRenderWindow_display(param->window);
        mouse_events(param, IN_GAME_MENU);
        sfRenderWindow_clear(param->window, sfBlack);
    }
    sfView_zoom(param->view, MENU_ZOOM);
    if (sfRenderWindow_isOpen(param->window))
        sfRenderWindow_setView(param->window, param->view);
}
