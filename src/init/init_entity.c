/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** Functions for entity
*/

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <SFML/Graphics.h>
#include "rpg.h"
#include "struct.h"
#include "my.h"
#include "associative.h"

void set_scale(entity_t *e, char *value, sfIntRect *rect)
{
    char *no_brackets = strdup_banned_chars(value, " {}");
    char **scale_value = NULL;

    if (!no_brackets)
        return;
    if (strcmp(value, "NULL") == 0) {
        free(no_brackets);
        return;
    }
    scale_value = my_str_to_word_array(no_brackets, ",");
    if (e->sprite)
        sfSprite_setScale(e->sprite,
            (sfVector2f){atof(scale_value[0]), atof(scale_value[1])});
    if (e->rect)
        sfRectangleShape_setScale(e->rect,
            (sfVector2f){atof(scale_value[0]), atof(scale_value[1])});
    free(no_brackets);
}

void set_pos(entity_t *e, char *value, sfIntRect *rect)
{
    char *no_brackets = strdup_banned_chars(value, " {}");
    char **scale_value = NULL;

    if (!no_brackets)
        return;
    if (strcmp(value, "NULL") == 0) {
        free(no_brackets);
        return;
    }
    scale_value = my_str_to_word_array(no_brackets, ",");
    if (e->sprite)
        sfSprite_setPosition(e->sprite,
            (sfVector2f){atof(scale_value[0]), atof(scale_value[1])});
    if (e->rect)
        sfRectangleShape_setPosition(e->rect,
            (sfVector2f){atof(scale_value[0]), atof(scale_value[1])});
    free(no_brackets);
}

void set_click(entity_t *e, char *value, sfIntRect *rect)
{
    if (strcmp(value, "NULL") == 0)
        return;
    for (int i = 0; func_list[i].func_name; i++) {
        if (strcmp(func_list[i].func_name, value) == 0)
            e->clicked = func_list[i].function;
    }
}

void set_hover(entity_t *e, char *value, sfIntRect *rect)
{
    if (strcmp(value, "NULL") == 0)
        return;
    for (int i = 0; func_list[i].func_name; i++) {
        if (strcmp(func_list[i].func_name, value) == 0)
            e->hovered = func_list[i].function;
    }
}

entity_t *create_entity(system_t *sys, int compo)
{
    entity_t *e = malloc(sizeof(entity_t));
    static unsigned int id = 0;

    if (e == NULL) {
        perror("create entity malloc failed");
        return NULL;
    }
    if (!push_to_list(&sys->e_list, e)) {
        free_entity(e);
        return NULL;
    }
    e->id = id;
    id++;
    set_entity(e, sys, compo);
    e->rect = NULL;
    e->clicked = NULL;
    e->hovered = NULL;
    return e;
}
