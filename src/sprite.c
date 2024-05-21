/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-nicolas.nunney
** File description:
** sprite.c
*/

#include <string.h>
#include <stdio.h>
#include "rpg.h"
#include "struct.h"

void create_sprite(parameters_t *param, entity_t *entity, char *value)
{
    if (strcmp(value, "TRUE") == 0) {
        entity->sprite = sfSprite_create();
        if (!entity->sprite)
            dprintf(2, "Error: failed to create sprite\n");
    }
    (void)param;
}

void set_sprite_texture(entity_t *e, char const *texture_path,
    sfIntRect *rect)
{
    sfTexture *texture = NULL;

    texture = sfTexture_createFromFile(texture_path, NULL);
    if (texture == NULL) {
        dprintf(2, "Error: unable to load %s as a texture\n", texture_path);
    }
    sfSprite_setTexture(e->sprite, texture, sfFalse);
    if (rect != NULL)
        sfSprite_setTextureRect(e->sprite, *rect);
}
