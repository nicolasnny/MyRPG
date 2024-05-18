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

void set_scale(parameters_t *param, entity_t *entity, char *value)
{
    double *scale_value = get_double_array(value);

    if (!scale_value)
        return;
    if (entity->sprite) {
        sfSprite_setScale(entity->sprite,
            (sfVector2f){scale_value[0], scale_value[1]});
    }
    if (entity->rect)
        sfRectangleShape_setScale(entity->rect,
            (sfVector2f){scale_value[0], scale_value[1]});
    free(scale_value);
}

void set_pos(parameters_t *param, entity_t *entity, char *value)
{
    double *pos_value = get_double_array(value);

    if (!pos_value)
        return;
    if (entity->sprite)
        sfSprite_setPosition(entity->sprite,
            (sfVector2f){pos_value[0], pos_value[1]});
    if (entity->rect)
        sfRectangleShape_setPosition(entity->rect,
            (sfVector2f){pos_value[0], pos_value[1]});
    free(pos_value);
}

void set_click(parameters_t *param, entity_t *entity, char *value)
{
    if (strcmp(value, "NULL") == 0)
        return;
    for (int i = 0; func_list[i].func_name; i++) {
        if (strcmp(func_list[i].func_name, value) == 0)
            entity->clicked = func_list[i].function;
    }
}

void set_hover(parameters_t *param, entity_t *entity, char *value)
{
    if (strcmp(value, "NULL") == 0)
        return;
    for (int i = 0; func_list[i].func_name; i++) {
        if (strcmp(func_list[i].func_name, value) == 0)
            entity->hovered = func_list[i].function;
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
