/*
** EPITECH PROJECT, 2023
** MY_RADAR
** File description:
** Functions related to the displaying
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include "rpg.h"

static void display_inventory(parameters_t *param)
{
    e_list_t *inventory_menu = get_entities(param->sys, INVENTORY | VISIBLE);
    sfText *txt = NULL;

    printf("displaying before null check\n");
    if (inventory_menu == NULL) {
        return;
    }
    printf("before create description");
    txt = create_inventory_description_text(inventory_menu->entity->sprite, "This sword is said to be the best in the world.\n Only true heros can use it.\n");
    printf("before checking id txt is null\n");
    if (txt == NULL) {
        return;
    }
    printf("before displaying\n");
    sfRenderWindow_drawText(param->window, txt, NULL);
    sfText_destroy(txt);
    clean_list(inventory_menu);
}

void display_sprites(parameters_t *param)
{
    e_list_t *list = get_entities(param->sys, VISIBLE);
    e_list_t *head = NULL;

    reverse_list(&list);
    head = list;
    while (list != NULL) {
        sfRenderWindow_drawSprite(param->window, list->entity->sprite, NULL);
        list = list->next;
    }
    display_inventory(param);
    clean_list(head);
}
