/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** set_inventory
*/

#include <SFML/Graphics.h>
#include "rpg.h"

static void set_inv_format(sfSprite *s)
{
    sfFloatRect size = {0};

    if (s == NULL)
        return;
    size = sfSprite_getGlobalBounds(s);
    while (size.width > SLOT_WIDTH * INVENTORY_SCALE * SLOT_ERROR_UP_MARGIN) {
        sfSprite_scale(s, (sfVector2f)
            {SLOT_ERROR_DOWN_MARGIN, SLOT_ERROR_DOWN_MARGIN});
        size = sfSprite_getGlobalBounds(s);
    }
    while (size.width < SLOT_WIDTH * INVENTORY_SCALE
        * SLOT_ERROR_DOWN_MARGIN) {
        sfSprite_scale(s, (sfVector2f)
            {SLOT_ERROR_UP_MARGIN, SLOT_ERROR_UP_MARGIN});
        size = sfSprite_getGlobalBounds(s);
    }
}

static void set_inventory_sprite_size(system_t *sys)
{
    e_list_t *list = get_entities(sys, INVENTORY);
    e_list_t *head = list;

    while (list) {
        set_inv_format(list->entity->sprite);
        list = list->next;
    }
    clean_list(head);
}

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

sfFloatRect get_rect(system_t *sys)
{
    e_list_t *bar_list = get_entities(sys, BAR);
    sfFloatRect rect = {0};

    rect.height = NEG_ERROR;
    if (bar_list == NULL)
        return rect;
    rect = sfSprite_getGlobalBounds(bar_list->entity->sprite);
    clean_list(bar_list);
    return rect;
}

void set_inventory_items_pos(system_t *sys)
{
    e_list_t *list = get_entities(sys, INVENTORY | VISIBLE);
    e_list_t *head = list;
    e_list_t *select = get_entities(sys, SELECTED);
    sfFloatRect rect = get_rect(sys);
    unsigned int index = 0;

    if (!list || rect.height == NEG_ERROR)
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
    set_inventory_sprite_size(sys);
    set_inventory_pos(sys);
    set_inventory_items_pos(sys);
}
