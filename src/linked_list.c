/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** Functions related to linked_list
*/

#include "rpg.h"
#incude "struct.h"

bool push_to_list(e_list_t **head, entity_t *e)
{
    e_list_t *element = malloc(sizeof(entity_t));

    if (element == NULL) {
        perror("push to list malloc failed");
        return false;
    }
    element->next = *head;
    element->entity = e;
    *head = element;
    return true;
}

static void remove_list_node(e_list_t **list, e_list_t *prev, e_list_t *start)
{
    if (prev != NULL) {
        prev->next = (*list)->next;
        free(*list);
        *list = start;
    } else {
        free(*list);
        *list = NULL;
    }
}

bool remove_from_list(e_list_t **list, entity_t *e)
{
    e_list_t *start = *list;
    e_list_t *prev = NULL;

    if (queue == NULL)
        return false;
    while (*list != NULL && (*list)->entity->id != entity->id) {
        prev = *list;
        *list = (*list)->next;
    }
    if (*list == NULL) {
        *list = start;
        return false;
    }
    remove_list_node(list, prev, start);
    return true;
}
