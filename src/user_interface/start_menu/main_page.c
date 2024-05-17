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
    entity_t *play_button = create_entity(param->sys, PLAY_BUTTON_PATH,
        NULL, MENU | CLICKABLE);
    sfSprite_setPosition(play_button->sprite, (sfVector2f){850, 300});
    add_click_hover(play_button, &set_to_play, &hovered);
}

static void create_option_menu(parameters_t *param)
{
    entity_t *option_button = create_entity(param->sys, OPTION_BUTTON_PATH,
        NULL, MENU | CLICKABLE);
    sfSprite_setPosition(option_button->sprite, (sfVector2f){850, 600});
    add_click_hover(option_button, &set_to_pause, &hovered);
}

static void create_quit_menu(parameters_t *param)
{
    entity_t *quit_button = create_entity(param->sys, QUIT_BUTTON_PATH,
        NULL, MENU | CLICKABLE);
    sfSprite_setPosition(quit_button->sprite, (sfVector2f){850, 900});
    add_click_hover(quit_button, &set_to_quit, &hovered);
}


static void create_background(parameters_t *param)
{
    entity_t *background = create_entity(param->sys, MENU_BACKGROUND_PATH,
        NULL, MENU);

    sfSprite_setScale(background->sprite, (sfVector2f){0.75, 0.75});
}

bool start_menu(parameters_t *param)
{
    create_background(param);
    create_play_menu(param);
    create_option_menu(param);
    create_quit_menu(param);
    while (param->game_state == PAUSE) {
        display_entities(param, MENU);
        sfRenderWindow_display(param->window);
        mouse_events(param, CLICKABLE);
        sfRenderWindow_clear(param->window, sfBlack);
    }
    return true;
}