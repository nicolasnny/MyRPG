/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** Functions related to the inventory
*/

#include <SFML/Graphics.h>
#include "rpg.h"
#include "struct.h"

static unsigned int get_list_len(e_list_t *list)
{
    unsigned int size = 0;

    while (list != NULL) {
        list = list->next;
        size++;
    }
    return size;
}

static bool is_empty_slot(e_list_t *list)
{
    if (get_list_len(list) >= INVENTORY_CAPACITY) {
        return false;
    }
    return true;
}

static bool remove_last_element(e_list_t **list)
{
    if (list == NULL) {
        return false;
    }
    while (*list && (*list)->next) {
        *list = (*list)->next;
    }
    if (*list == NULL) {
        return false;
    }
    return remove_entity_from_list(list, (*list)->entity);
}

bool add_element_to_inventory(system_t *sys, entity_t *e)
{
    e_list_t *inventory = get_entities(sys, INVENTORY | ITEM);
    e_list_t *temp = inventory;

    if (is_empty_slot(temp)) {
        if (inventory)
            clean_list(inventory);
        set_entity(e, sys, INVENTORY);
        return true;
    }
    if (inventory)
        clean_list(inventory);
    set_entity(e, sys, INVENTORY);
    return remove_last_element(&sys->component[INVENTORY]);
}
