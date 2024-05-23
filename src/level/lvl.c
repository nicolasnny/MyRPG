/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** lvl
*/

#include "rpg.h"

void set_lvl_pos(system_t *sys)
{
    sfVector2f pos = {0};
    e_list_t *xp = get_entities(sys, XP | VISIBLE);
    e_list_t *player = get_entities(sys, PLAYER | VISIBLE);
    sfVector2f player_center_pos = {0};

    if (xp == NULL || player == NULL)
        return;
    player_center_pos = get_center(player->entity->sprite);
    pos.x = player_center_pos.x - DEFAULT_VIEW_SIZE_X / 2 + DEFAULT_VIEW_SIZE_X
    * XP_WIDTH;
    pos.y = player_center_pos.y - DEFAULT_VIEW_SIZE_Y / 2 + DEFAULT_VIEW_SIZE_Y
    * XP_HEIGHT;
    sfSprite_setPosition(xp->entity->sprite, pos);
    clean_list(xp);
    clean_list(player);
}

void move_lvl_rect(system_t *sys)
{
    e_list_t *xp = get_entities(sys, XP);
    sfIntRect rect = {0};

    if (xp == NULL || xp->entity->sprite == NULL)
        return;
    rect = sfSprite_getTextureRect(xp->entity->sprite);
    printf("rect => top: %d, height: %d\n", rect.top, rect.height);
    rect.top -= rect.height;
    if (rect.top < 0)
        rect.top = 0;
    sfSprite_setTextureRect(xp->entity->sprite, rect);
    clean_list(xp);
}