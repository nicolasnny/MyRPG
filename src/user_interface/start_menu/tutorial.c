/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-nicolas.nunney
** File description:
** tutorial.c
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "rpg.h"
#include "struct.h"

static void set_to_next(e_list_t *list)
{
    if (list->next && list->next->entity) {
        if (list->next->entity->name)
            free(list->next->entity->name);
        list->next->entity->name = strdup("ACTUAL");
    }
}

static void set_to_prev(e_list_t *list)
{
    if (list->entity->name)
        free(list->entity->name);
    list->entity->name = strdup("ACTUAL");
}

int next_image(parameters_t *param, entity_t *entity, bool state)
{
    e_list_t *tuto_images = get_entities(param->sys, IMAGE);
    e_list_t *temp = tuto_images;

    if (!tuto_images)
        return ERROR;
    while (temp && temp->next) {
        if (temp->entity->name && strcmp("ACTUAL", temp->entity->name) == 0) {
            free(temp->entity->name);
            temp->entity->name = NULL;
            set_to_next(temp);
            break;
        }
        temp = temp->next;
    }
    clean_list(tuto_images);
    (void)entity;
    (void)state;
    return SUCCESS;
}

int prev_image(parameters_t *param, entity_t *entity, bool state)
{
    e_list_t *tuto_images = get_entities(param->sys, IMAGE);
    e_list_t *temp = tuto_images;

    if (!tuto_images)
        return ERROR;
    while (temp && temp->next) {
        if (temp->next->entity->name &&
            strcmp("ACTUAL", temp->next->entity->name) == 0) {
            free(temp->next->entity->name);
            temp->next->entity->name = NULL;
            set_to_prev(temp);
            break;
        }
        temp = temp->next;
    }
    clean_list(tuto_images);
    (void)entity;
    (void)state;
    return SUCCESS;
}

static void disp_images(parameters_t *param)
{
    entity_t *image = get_entity_by_name(param->sys, "ACTUAL");

    if (!image) {
        return;
    }
    if (image->sprite)
        sfRenderWindow_drawSprite(param->window, image->sprite, NULL);
}

int tutorial(parameters_t *param, entity_t *entity, bool state)
{
    e_list_t *list = get_entities(param->sys, TUTORIAL);
    e_list_t *tmp = list;

    (void)entity;
    (void)state;
    while (param->game_state == PAUSE) {
        display_entities(param, TUTORIAL);
        disp_images(param);
        sfRenderWindow_display(param->window);
        mouse_events(param, TUTORIAL, tmp);
        sfRenderWindow_clear(param->window, sfBlack);
    }
    clean_list(list);
    return true;
}
