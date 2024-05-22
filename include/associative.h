/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-nicolas.nunney
** File description:
** associative.h
*/

#ifndef ASSOCIATIVE_H
    #define ASSOCIATIVE_H
    #include "struct.h"
    #include "rpg.h"

typedef struct conf_function_s {
    char *func_name;
    int (*function)(parameters_t *, entity_t *, bool state);
} conf_function_t;

typedef struct conf_param_s {
    char *param;
    void (*exec)(parameters_t *param, entity_t *entity, char *value);
} conf_param_t;

typedef struct conf_compo_s {
    char *component;
    int associate;
} conf_compo_t;

static const conf_function_t func_list[] = {
    {"set_to_play", &set_to_play},
    {"set_to_quit", &set_to_quit},
    {"set_to_pause", &set_to_pause},
    {"window_size:1920x1080", &set_1920x1080},
    {"window_size:2560x1600", &set_2560x1600},
    {"hovered", &hovered},
    {"init_inventory", &init_inventory},
    {"options_menu", &options_menu},
    {"start_menu", &start_menu},
    {"kill_entity", &kill_entity},
    {"set_music_volume_up", &set_music_volume_up},
    {"set_music_volume_down", &set_music_volume_down},
    {"reset_music_volume", &reset_music_volume},
    {"set_sound_volume_up", &set_sound_volume_up},
    {"set_sound_volume_down", &set_sound_volume_down},
    {"reset_sound_volume", &reset_sound_volume},
    {NULL, NULL},
};

static const conf_compo_t compo_list[] = {
    {"PLAYER", PLAYER},
    {"NPC", NPC},
    {"VISIBLE", VISIBLE},
    {"MENU", MENU},
    {"MOB", MOB},
    {"CLICKABLE", CLICKABLE},
    {"SETTINGS", SETTINGS},
    {"IN_GAME_MENU", IN_GAME_MENU},
    {"INVENTORY", INVENTORY},
    {"SELECTED", SELECTED},
    {"BAR", BAR},
    {"ON_MAP", ON_MAP},
    {"LOADING", LOADING},
    {"HEART", HEART},
    {NULL, 0},
};

static const conf_param_t param_list[] = {
    {"TEXTURE", &set_texture},
    {"SPRITE", &create_sprite},
    {"RECT", &create_rectangle},
    {"SCALE", &set_scale},
    {"POS", &set_pos},
    {"CLICK", &set_click},
    {"HOVER", &set_hover},
    {"NAME", &set_name},
    {"RUN_ON_START", &run_on_start},
    {NULL, NULL},
};

#endif
