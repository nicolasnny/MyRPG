/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** set_inventory
*/

#include <SFML/Graphics.h>
#include "rpg.h"

static void set_sprite_slot(unsigned int index, sfSprite *s,
    sfFloatRect *bar_rect)
{
    sfVector2f pos = {bar_rect->left, bar_rect->top};

    pos.x +=
        SLOT1_WIDTH * INVENTORY_SCALE
        + SLOT_WIDTH * INVENTORY_SCALE * index;
    pos.y += SLOT_TOP * INVENTORY_SCALE;
    sfSprite_setPosition(s, pos);
}

static void set_selected_sprite(sfSprite *s, sfFloatRect *bar_rect)
{
    sfVector2f pos = {bar_rect->left, bar_rect->top};

    pos.x += SLOT_TOP * INVENTORY_SCALE;
    pos.y += SLOT_TOP * INVENTORY_SCALE;
    sfSprite_setPosition(s, pos);
}

void set_inventory_items_pos(system_t *sys)
{
    entity_t *bar = get_entities(sys, BAR)->entity;
    e_list_t *list = get_entities(sys, INVENTORY | VISIBLE);
    e_list_t *head = list;
    e_list_t *select = get_entities(sys, SELECTED);
    sfFloatRect rect = sfSprite_getGlobalBounds(bar->sprite);
    unsigned int index = 0;

    if (!list)
        return;
    if (select != NULL)
        set_selected_sprite(select->entity->sprite, &rect);
    while (list) {
        set_sprite_slot(index, list->entity->sprite, &rect);
        index++;
        list = list->next;
    }
    clean_list(head);
    clean_list(select);
}

void refresh_inventory_pos(system_t *sys)
{
    set_inventory_pos(sys);
    set_inventory_items_pos(sys);
}
