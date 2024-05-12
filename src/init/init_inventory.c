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
    sfSprite_setScale(s, (sfVector2f){3, 3});
    pos.x = WIN_WIDTH / 2 - sfSprite_getGlobalBounds(s).width / 2;
    pos.y = WIN_HEIGHT / 2 - sfSprite_getGlobalBounds(s).height / 2;
    sfSprite_setPosition(s, pos);
}

int init_inventory(parameters_t *param)
{
    sfIntRect texture_rect = {0, 0, INVENTORY_WIDTH, INVENTORY_HEIGHT};
    entity_t *inventory = create_entity(param->sys,
        INVENTORY_SPRITE, &texture_rect, INVENTORY | VISIBLE); //tmp visiblr

    if (inventory == NULL) {
        dprintf(2, "Error: unable to create the inventory");
        return ERROR;
    }
    set_inventory_pos(inventory->sprite);
    return SUCCESS;
}