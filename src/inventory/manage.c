/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** Functions related to inventory management
*/

#include <stdio.h>
#include <stdbool.h>
#include "rpg.h"

static bool set_new_select(system_t *sys, entity_t *e)
{
    e_list_t *select_list = get_entities(sys, SELECTED | ITEM | VISIBLE);
    entity_t *prev_select = NULL;
    bool ret = false;

    if (select_list != NULL) {
        prev_select = select_list->entity;
        unset_entity(sys, prev_select, SELECTED);
        set_entity(prev_select, sys, INVENTORY);
    }
    unset_entity(sys, e, INVENTORY);
    ret = set_entity(e, sys, SELECTED);
    refresh_inventory_pos(sys);
    if (select_list)
        clean_list(select_list);
    return ret;
}

static bool select_item(system_t *sys, unsigned int slot_nb)
{
    e_list_t *inventory_list = get_entities(sys, INVENTORY | ITEM | VISIBLE);
    unsigned int index = 1;

    if (inventory_list == NULL)
        return false;
    while (inventory_list && index < slot_nb) {
        inventory_list = inventory_list->next;
        index++;
    }
    if (inventory_list == NULL)
        return false;
    return set_new_select(sys, inventory_list->entity);
}

void grab_drop_events(parameters_t *param)
{
    if (sfKeyboard_isKeyPressed(sfKeyA)) {
            get_item(param);
        }
    if (sfKeyboard_isKeyPressed(sfKeyE)) {
        drop_selected_item(param->sys);
    }
}

void change_selected_item(system_t *sys)
{
    if (sfKeyboard_isKeyPressed(sfKeyNum1)
        || sfKeyboard_isKeyPressed(sfKeyNumpad1)) {
        if (!select_item(sys, 1))
            printf("Unable to select item number 1 !\n");
    }
    if (sfKeyboard_isKeyPressed(sfKeyNum2)
        || sfKeyboard_isKeyPressed(sfKeyNumpad2)) {
        if (!select_item(sys, 2))
            printf("Unable to select item number 2!\n");
    }
    if (sfKeyboard_isKeyPressed(sfKeyNum3)
        || sfKeyboard_isKeyPressed(sfKeyNumpad3)) {
        if (!select_item(sys, 3))
            printf("Unable to select item number 3 !\n");
    }
    if (sfKeyboard_isKeyPressed(sfKeyNum4)
        || sfKeyboard_isKeyPressed(sfKeyNumpad4)) {
        if (!select_item(sys, 4))
            printf("Unable to select item number 4 !\n");
    }
}
