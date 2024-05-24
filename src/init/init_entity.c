/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** Functions for entity
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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
    entity->scale = (sfVector2f){scale_value[0], scale_value[1]};
    (void)param;
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
    if (entity->text)
        sfText_setPosition(entity->text,
            (sfVector2f){pos_value[0], pos_value[1]});
    free(pos_value);
    (void)param;
}

void set_click(parameters_t *param, entity_t *entity, char *value)
{
    if (strcmp(value, "NULL") == 0)
        return;
    for (int i = 0; func_list[i].func_name; i++) {
        if (strcmp(func_list[i].func_name, value) == 0)
            entity->clicked = func_list[i].function;
    }
    (void)param;
}

void set_hover(parameters_t *param, entity_t *entity, char *value)
{
    (void)param;
    if (strcmp(value, "NULL") == 0)
        return;
    for (int i = 0; func_list[i].func_name; i++) {
        if (strcmp(func_list[i].func_name, value) == 0)
            entity->hovered = func_list[i].function;
    }
}

static void init_entity_param(entity_t *e)
{
    e->rect = NULL;
    e->clicked = NULL;
    e->hovered = NULL;
    e->name = NULL;
    e->pos = (sfVector2f){NEG_ERROR, NEG_ERROR};
    e->scale = (sfVector2f){DEFAULT_SCALE, DEFAULT_SCALE};
    e->text = NULL;
    e->sprite = NULL;
}

entity_t *create_entity(parameters_t *param, int compo)
{
    entity_t *e = malloc(sizeof(entity_t));
    static unsigned int id = 0;

    if (e == NULL)
        return NULL;
    e->id = id;
    if (!push_to_list(&param->sys->e_list, e)) {
        free_entity(e);
        return NULL;
    }
    id++;
    set_entity(e, param->sys, compo);
    init_entity_param(e);
    e->entity_time = sfClock_getElapsedTime(param->clock);
    return e;
}
