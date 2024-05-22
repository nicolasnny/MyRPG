/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** Function to set heart position
*/

#include "rpg.h"

void refresh_heart_position(system_t *sys)
{
    sfVector2f pos = {0};
    e_list_t *hearts = get_entities(sys, HEART | VISIBLE);
    e_list_t *player = get_entities(sys, PLAYER | VISIBLE);
    sfVector2f player_center_pos = {0};
    unsigned int index = 0;

    if (hearts == NULL || player == NULL)
        return;
    player_center_pos = get_center(player->entity->sprite);
    while (hearts != NULL) {
        pos.x = player_center_pos.x - DEFAULT_VIEW_SIZE_X * HEART_LEFT_POURCENTAGE
        + index * sfSprite_getGlobalBounds(hearts->entity->sprite).width;
        pos.y = player_center_pos.y + DEFAULT_VIEW_SIZE_Y *
            INVENTORY_HEIGHT_POURCENTAGE / 2 - sfSprite_getGlobalBounds(hearts->entity->sprite).height / 2;
        sfSprite_setPosition(hearts->entity->sprite, pos);
        hearts = hearts->next;
        index++;
    }
    clean_list(hearts);
    clean_list(player);
}
