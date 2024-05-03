/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-nicolas.nunney
** File description:
** main_page.c
*/

#include <stdio.h>
#include <stdbool.h>
#include "rpg.h"
#include "struct.h"

static void reset_state(parameters_t *param)
{
    e_list_t *to_reset = get_entities(param->sys, MENU | CLICKABLE);

    while (to_reset) {
        reset_sprite(to_reset->entity);
        to_reset = to_reset->next;
    }
}

static void create_play_menu(parameters_t *param)
{
    create_entity(param->sys, PLAY_BUTTON_PATH, NULL, VISIBLE | MENU | CLICKABLE);
}

static void create_quit_menu(parameters_t *param)
{
    entity_t *quit_button = create_entity(param->sys, PLAY_BUTTON_PATH,
        NULL, VISIBLE | MENU | CLICKABLE);
    add_click_hover(quit_button, NULL, &hovered);
}

static void create_option_menu(parameters_t *param)
{
    create_entity(param->sys, PLAY_BUTTON_PATH, NULL, VISIBLE | MENU | CLICKABLE);
}

bool start_menu(parameters_t *param)
{
    int game_stat = SELECT;

    create_entity(param->sys, MENU_BACKGROUND_PATH, NULL, VISIBLE | MENU);
    entity_t *quit_button = create_entity(param->sys, PLAY_BUTTON_PATH,
        NULL, VISIBLE | MENU | CLICKABLE);
    add_click_hover(quit_button, NULL, &hovered);
    // create_option_menu(param);
    // create_play_menu(param);
    // create_quit_menu(param);
    while (game_stat == SELECT) {
        display_sprites(param, VISIBLE | MENU);
        sfRenderWindow_display(param->window);
        mouse_events(param, CLICKABLE);
        sfRenderWindow_clear(param->window, sfBlack);
        reset_state(param);
    }
    return true;
}