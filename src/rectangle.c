/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-nicolas.nunney
** File description:
** rectangle.c
*/

#include <stdio.h>
#include <string.h>
#include "rpg.h"
#include "struct.h"

void create_rectangle(parameters_t *param, entity_t *entity, char *value)
{
    if (strcmp(value, "TRUE") == 0) {
        entity->rect = sfRectangleShape_create();
        if (!entity->rect)
            dprintf(2, "Error: failed to create sprite\n");
    }
}

void set_rectangle_texture(entity_t *e, char const *texture_path,
    sfIntRect *rect)
{
    sfTexture *texture = NULL;

    texture = sfTexture_createFromFile(texture_path, rect);
    if (texture == NULL) {
        dprintf(2, "Error: unable to load %s as a texture\n", texture_path);
    }
    sfRectangleShape_setTexture(e->rect, texture, sfFalse);
}
