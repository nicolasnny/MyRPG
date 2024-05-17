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

bool is_empty_slot(e_list_t *list)
{
    if (get_list_len(list) >= INVENTORY_CAPACITY) {
        return false;
    }
    return true;
}
