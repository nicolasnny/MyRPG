/*
** EPITECH PROJECT, 2023
** MY_RADAR
** File description:
** Functions to clean my radar
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "rpg.h"

void free_str_array(char **array)
{
    for (unsigned int i = 0; array[i]; i++) {
        free(array[i]);
    }
    free(array);
}

void free_entity(entity_t *e)
{
    if (e == NULL) {
        return;
    }
    if (e->sprite != NULL) {
        sfSprite_destroy(e->sprite);
    }
    if (e->name != NULL)
        free(e->name);
    if (e->rect != NULL)
        sfRectangleShape_destroy(e->rect);
    free(e);
}

static void delete_entity_list(e_list_t *list)
{
    while (list) {
        free_entity(list->entity);
        list = list->next;
    }
}

static void free_system(system_t *sys)
{
    e_list_t *next = NULL;

    delete_entity_list(sys->e_list);
    for (unsigned int i = 0; i < __END__; i++) {
        while (sys->component[i]) {
            next = sys->component[i]->next;
            free(sys->component[i]);
            sys->component[i] = next;
        }
    }
    free(sys);
}

void clean(parameters_t *param)
{
    free_system(param->sys);
    return;
}
