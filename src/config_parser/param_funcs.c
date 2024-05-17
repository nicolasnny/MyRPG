/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-nicolas.nunney
** File description:
** param_funcs.c
*/

#include <string.h>
#include "rpg.h"
#include "struct.h"
#include "associative.h"

void set_texture(entity_t *entity, char *value,
    sfIntRect *rect)
{
    if (strcmp("NULL", value) != 0) {
        if (entity->sprite)
            set_sprite_texture(entity, value, rect);
        if (entity->rect)
            set_rectangle_texture(entity, value, rect);
    }
}
