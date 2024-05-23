/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-nicolas.nunney
** File description:
** hovering.c
*/

#include "rpg.h"
#include "struct.h"

int hovered(parameters_t *param, entity_t *entity, bool hovered)
{
    if (hovered) {
        sfSprite_setScale(entity->sprite,
            (sfVector2f){entity->scale.x + 0.25, entity->scale.y + 0.25});
    } else {
        sfSprite_setScale(entity->sprite,
            (sfVector2f){entity->scale.x, entity->scale.y});
    }
    (void)param;
    return SUCCESS;
}
