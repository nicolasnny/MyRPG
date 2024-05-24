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
    e_list_t *inventory = get_entities(sys, INVENTORY | ITEM | VISIBLE);
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

static void use_item(parameters_t *param)
{
    e_list_t *select_item = get_entities(param->sys,
        SELECTED | ITEM | VISIBLE);

    if (select_item == NULL)
        return;
    if (!sfKeyboard_isKeyPressed(sfKeyF)) {
        clean_list(select_item);
        return;
    }
    if (select_item->entity->clicked != NULL) {
        select_item->entity->clicked(param, select_item->entity, false);
        unset_entity(param->sys, select_item->entity, VISIBLE | INVENTORY);
    }
    clean_list(select_item);
}

void item_management(parameters_t *param)
{
    change_selected_item(param->sys);
    grab_drop_events(param);
    use_item(param);
}
