/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** heart
*/

#include "rpg.h"

static void heart_pos(entity_t *e, sfVector2f *player_center_pos, int index)
{
    sfVector2f pos = {0};

    pos.x = player_center_pos->x - DEFAULT_VIEW_SIZE_X * HEART_LEFT_POURCENTAGE
        + index * sfSprite_getGlobalBounds(e->sprite).width;
        pos.y = player_center_pos->y + DEFAULT_VIEW_SIZE_Y *
            HEART_HEIGHT_POURCENTAGE / 2;
    sfSprite_setPosition(e->sprite, pos);
}

void refresh_heart_position(system_t *sys)
{
    e_list_t *hearts = get_entities(sys, HEART | VISIBLE);
    e_list_t *player = get_entities(sys, PLAYER | VISIBLE);
    sfVector2f player_center_pos = {0};
    unsigned int index = 0;

    if (hearts == NULL || player == NULL)
        return;
    player_center_pos = get_center(player->entity->sprite);
    while (hearts != NULL) {
        heart_pos(hearts->entity, &player_center_pos, index);
        hearts = hearts->next;
        index++;
    }
    clean_list(hearts);
    clean_list(player);
}

static bool wait_time(double time_to_wait)
{
    static sfClock *clock = NULL;

    if (clock == NULL) {
        clock = sfClock_create();
        return true;
    }
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) > time_to_wait) {
        sfClock_restart(clock);
        return true;
    }
    return false;
}

void remove_life(system_t *sys)
{
    e_list_t *list = get_entities(sys, FULL_LIFE);
    entity_t *e = NULL;

    if (list == NULL)
        return;
    if (!wait_time(LOSE_LIFE_COOLDOWN)) {
        clean_list(list);
        return;
    }
    e = list->entity;
    unset_entity(sys, e, FULL_LIFE);
    set_entity(e, sys, LOW_LIFE);
    move_heart_rect(e->sprite);
    clean_list(list);
}

bool is_player_alive(system_t *sys)
{
    e_list_t *list = get_entities(sys, FULL_LIFE);
    e_list_t *temp = list;

    if (!list)
        return false;
    if (get_list_size(temp) <= 0) {
        clean_list(list);
        return false;
    }
    clean_list(list);
    return true;
}
