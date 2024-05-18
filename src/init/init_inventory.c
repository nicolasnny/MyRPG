/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** Function to initialize the inventory
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include "rpg.h"
#include "struct.h"

static void set_inventory_pos(entity_t *entity)
{
    sfVector2f pos = {0};

    if (!entity) {
        return;
    }
    sfSprite_setScale(entity->sprite,
        (sfVector2f){INVENTORY_SCALE, INVENTORY_SCALE});
    pos.x =
        WIN_WIDTH / 2 - sfSprite_getGlobalBounds(entity->sprite).width / 2;
    pos.y = WIN_HEIGHT * INVENTORY_HEIGHT_POURCENTAGE -
        sfSprite_getGlobalBounds(entity->sprite).height / 2;
    sfSprite_setPosition(entity->sprite, pos);
}

int init_inventory(parameters_t *param, entity_t *entity, bool state)
{
    set_inventory_pos(entity);
    set_inventory_items_pos(param->sys);
    return SUCCESS;
}
