/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-nicolas.nunney
** File description:
** hovering.c
*/

#include "rpg.h"
#include "struct.h"

void reset_sprite(entity_t *entity)
{
    // sfVector2f cur_pos = sfSprite_getPosition(entity->sprite);
    // sfFloatRect size = sfSprite_getGlobalBounds(entity->sprite);

    // sfSprite_setPosition(entity->sprite,
    //     (sfVector2f){cur_pos.x - 0.125 * size.width,
    //         cur_pos.x - 0.125 * size.height});
    // sfSprite_setScale(entity->sprite, (sfVector2f){1.0, 1.0});
    return;
}

int hovered(parameters_t *param, system_t *system, entity_t *entity,
    bool hovered)
{
    if (hovered) {
        sfSprite_setScale(entity->sprite, (sfVector2f){1.25, 1.25});
    } else {
        sfSprite_setScale(entity->sprite, (sfVector2f){1.0, 1.0});
    }
    return SUCCESS;
}