/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** Get entities from the system
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "rpg.h"
#include "struct.h"

static void add_list(e_list_t **new_list, e_list_t *src)
{
    e_list_t *new = NULL;

    printf("before looping in src\n");
    if (src == NULL)
        printf("null at start\n");
    while (src != NULL) {
        new = malloc(sizeof(e_list_t));
        if (new == NULL) {
            perror("add list malloc failed");
            return;
        }
        printf("before ett null check\n");
        if (src->entity != NULL)
            printf("the ett is noy null\n");
        printf("before setting new entt: %d\n", src->entity->id);
        new->entity = src->entity;
        printf("before setting next\n");
        new->next = *new_list;
        //printf("moving head\n");
        *new_list = new;
        //printf("going to src next\n");
        src = src->next;
    }
}

static e_list_t *get_pot_list(system_t *sys, int component)
{
    e_list_t *list = NULL;

    for (unsigned int n = 1; n < __END__; n += 1) {
        if (component & 1 << n) {
            //printf("before add list\n");
            add_list(&list, sys->component[1 << n]);
            //printf("after\n");
        }
    }
    return list;
}

static bool check_entity(entity_t *entity, system_t *sys, int component)
{
    for (unsigned int n = 1; n != __END__; n += 1) {
        if ((component & 1 << n) &&
            !entity_in_list(sys->component[n << 1], entity)) {
            return false;
        }
    }
    return true;
}

e_list_t *get_entities(system_t *sys, int component)
{
    ///printf("before getting pot list\n");
    e_list_t *s_list = get_pot_list(sys, component);
    e_list_t *rep_list = NULL;

    // printf("before looping in pot lidt\n");
    while (s_list != NULL) {
        if (check_entity(s_list->entity, sys, component)) {
            push_to_list(&rep_list, s_list->entity);
        }
        s_list = s_list->next;
    }
    return rep_list;
}
