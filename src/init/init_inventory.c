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

static void set_inventory_pos(sfSprite *s)
{
    sfVector2f pos = {0};

    if (s == NULL) {
        return;
    }
    sfSprite_setScale(s, (sfVector2f){INVENTORY_SCALE, INVENTORY_SCALE});
    pos.x = WIN_WIDTH / 2 - sfSprite_getGlobalBounds(s).width / 2;
    pos.y = WIN_HEIGHT * INVENTORY_HEIGHT_POURCENTAGE - sfSprite_getGlobalBounds(s).height / 2;
    sfSprite_setPosition(s, pos);
}

int init_inventory(parameters_t *param)
{
    entity_t *inventory = create_entity(param->sys,
        INVENTORY_SPRITE, NULL, BAR | VISIBLE);

    if (inventory == NULL) {
        dprintf(2, "Error: unable to create the inventory");
        return ERROR;
    }
    set_inventory_pos(inventory->sprite);
    set_inventory_items_pos(param->sys);
    return SUCCESS;
}