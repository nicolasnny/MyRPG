/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** Functiond to know if enemy is in player attack range
*/

#include <stddef.h>
#include <stdbool.h>
#include <math.h>
#include "rpg.h"

sfVector2f get_center(sfSprite *s)
{
    sfVector2f pos = {0};

    if (s == NULL)
        return pos;
    pos = sfSprite_getPosition(s);
    pos.x += sfSprite_getGlobalBounds(s).width / 2;
    pos.y += sfSprite_getGlobalBounds(s).height / 2;
    return pos;
}

double get_distance_bewteen_pos(sfVector2f *pa, sfVector2f *pb)
{
    double height_dist = 0;
    double width_dist = 0;
    double result = 0;

    if (pa == NULL || pb == NULL)
        return NEG_ERROR;
    width_dist = (pb->x - pa->x) * (pb->x - pa->x);
    height_dist = (pb->y - pa->y) * (pb->y - pa->y);
    result = sqrt(width_dist + height_dist);
    if (result < 0)
        return result * -1;
    return result;
}

bool enemy_in_range(entity_t *player, entity_t *enemy, unsigned int range)
{
    sfVector2f player_center = {0};
    sfVector2f enemy_center = {0};
    double dist_between = 0;

    if (player == NULL || enemy == NULL)
        return false;
    player_center = get_center(player->sprite);
    enemy_center = get_center(enemy->sprite);
    dist_between = get_distance_bewteen_pos(&player_center, &enemy_center);
    if (dist_between == NEG_ERROR || dist_between > range)
        return false;
    return true;
}
