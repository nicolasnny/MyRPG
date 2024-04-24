/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** Functions for entity
*/

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <SFML/Graphics.h>
#include "rpg.h"
#include "struct.h"

static entity_t *set_sprite(entity_t *e, char const *texture_path,
    sfIntRect *rect)
{
    sfTexture *texture = NULL;
    sfSprite *sprite = sfSprite_create();

    if (sprite == NULL) {
        free(e);
        return NULL;
    }
    texture = sfTexture_createFromFile(texture_path, rect);
    if (texture == NULL) {
        free(e);
        sfSprite_destroy(sprite);
    }
    sfSprite_setTexture(sprite, texture, sfFalse);
    e->sprite = sprite;
    return e;
}

static bool set_texture(entity_t *e, char const *texture_path, sfIntRect *rect)
{
    if (texture_path != NULL) {
        e = set_sprite(e, texture_path, rect);
        if (e == NULL) {
            return false;
        }
    }
    return true;
}

entity_t *create_entity(system_t *sys, char const *texture_path,
    sfIntRect *rect, int compo)
{
    entity_t *e = malloc(sizeof(entity_t));
    static unsigned int id = 0;

    if (e == NULL) {
        perror("create entity malloc failed");
        return NULL;
    }
    if (!set_texture(e, texture_path, rect)) {
        return NULL;
    }
    if (!push_to_list(&sys->e_list, e)) {
        free_entity(e);
        return NULL;
    }
    e->id = id;
    id++;
    set_entity(e, sys, compo);
    return e;
}
