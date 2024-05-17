/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** Functions related to linked_list
*/

#include <stdlib.h>
#include <stdio.h>
#include "rpg.h"
#include "struct.h"

bool entity_in_list(e_list_t *list, entity_t *e)
{
    while (list != NULL && list->entity != NULL && list->entity->id != e->id) {
        list = list->next;
    }
    if (list == NULL) {
        return false;
    }
    return true;
}

bool push_to_list(e_list_t **head, entity_t *e)
{
    e_list_t *element = NULL;

    if (entity_in_list(*head, e)) {
        return true;
    }
    element = malloc(sizeof(e_list_t));
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

    if (*list == NULL)
        return false;
    while (*list != NULL && (*list)->entity->id != e->id) {
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

bool clean_list(e_list_t *list)
{
    e_list_t *next = NULL;

    while (list != NULL) {
        next = list->next;
        free(list);
        list = next;
    }
    return true;
}

void display_entity_id(e_list_t *list)
{
    printf("NULL");
    while (list != NULL && list->entity != NULL) {
        printf(" -> %d", list->entity->id);
        list = list->next;
    }
    printf("\n");
}
