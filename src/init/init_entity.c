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
        dprintf(2, "Error: sfSprite_create failed\n");
        free(e);
        return NULL;
    }
    texture = sfTexture_createFromFile(texture_path, rect);
    if (texture == NULL) {
        dprintf(2, "Error: unable to load %s as a texture\n", texture_path);
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

// static sfVector2f get_pos_from_sprite(sfSprite *s, char const *msg)
// {
//     sfVector2f pos = {0};
//     unsigned int

//     if (s == NULL || msg == NULL) {
//         return pos;
//     }

// }

// bool set_entity_text(entity_t *e, char const *msg)
// {
//     sfVector2f *pos = get_pos_from_sprite(e->sprite, msg);

// }

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

