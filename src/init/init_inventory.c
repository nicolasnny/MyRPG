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

void set_inventory_pos(system_t *sys)
{
    sfVector2f pos = {0};
    e_list_t *i_bar = get_entities(sys, BAR | VISIBLE);
    e_list_t *player = get_entities(sys, PLAYER | VISIBLE);
    sfVector2f player_center_pos = {0};

    if (i_bar == NULL || player == NULL)
        return;
    player_center_pos = get_center(player->entity->sprite);
    sfSprite_setScale(i_bar->entity->sprite, (sfVector2f)
        {INVENTORY_SCALE, INVENTORY_SCALE});
    pos.x = player_center_pos.x - sfSprite_getGlobalBounds
        (i_bar->entity->sprite).width / 2;
    pos.y = player_center_pos.y + DEFAULT_VIEW_SIZE_Y *
        INVENTORY_HEIGHT_POURCENTAGE
        / 2 - sfSprite_getGlobalBounds(i_bar->entity->sprite).height / 2;
    sfSprite_setPosition(i_bar->entity->sprite, pos);
    clean_list(i_bar);
    clean_list(player);
}

int init_inventory(parameters_t *param, entity_t *entity, bool state)
{
    set_inventory_pos(param->sys);
    set_inventory_items_pos(param->sys);
    (void)entity;
    (void)state;
    return SUCCESS;
}
