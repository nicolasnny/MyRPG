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

static void set_sprite_pos(parameters_t *param)
{
    e_list_t *menu = get_entities(param->sys, IN_GAME_MENU);
    int offset = -100;
    sfVector2f center = sfView_getCenter(param->view);
    sfFloatRect size = sfSprite_getGlobalBounds(menu->entity->sprite);

    sfView_zoom(param->view, 1.5);
    sfRenderWindow_setView(param->window, param->view);
    while (menu) {
        if (menu->entity->name && strcmp(menu->entity->name, "map") != 0) {
            sfSprite_setPosition(menu->entity->sprite,
                (sfVector2f){center.x - size.width / 2,
                (center.y - size.height / 2) + offset});
            offset += 100;
        }
        menu = menu->next;
    }
}

void in_game_menu(parameters_t *param)
{
    set_sprite_pos(param);
    param->game_state = PAUSE;
    while (param->game_state == PAUSE) {
        display_entities(param, IN_GAME_MENU);
        sfRenderWindow_display(param->window);
        mouse_events(param, IN_GAME_MENU);
        sfRenderWindow_clear(param->window, sfBlack);
    }
    sfView_zoom(param->view, 0.66666666666667);
    sfRenderWindow_setView(param->window, param->view);
}
