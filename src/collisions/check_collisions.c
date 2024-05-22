/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** Functions to check collisions by hit box
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include "rpg.h"
#include "struct.h"

#include <unistd.h>

static bool sprite_contains(sfSprite *s, sfVector2f *pos)
{
    sfFloatRect s_bounds = sfSprite_getGlobalBounds(s);

    if (pos->x < s_bounds.left || pos->x > s_bounds.left + s_bounds.width) {
        return false;
    }
    if (pos->y < s_bounds.top || pos->y > s_bounds.top + s_bounds.height) {
        return false;
    }
    return true;
}

static bool sprite_collide(sfSprite *a, sfSprite *b)
{
    sfFloatRect b_bounds = sfSprite_getGlobalBounds(b);
    sfVector2f pos = {0};

    pos = (sfVector2f){b_bounds.left, b_bounds.top};
    if (sprite_contains(a, &pos))
        return true;
    pos = (sfVector2f){b_bounds.left + b_bounds.width, b_bounds.top};
    if (sprite_contains(a, &pos)) {
        return true;
    }
    pos = (sfVector2f){b_bounds.left, b_bounds.top + b_bounds.height};
    if (sprite_contains(a, &pos)) {
        return true;
    }
    pos = (sfVector2f){b_bounds.left + b_bounds.width,
        b_bounds.top + b_bounds.height};
    if (sprite_contains(a, &pos)) {
        return true;
    }
    return false;
}

static void check_monsters(system_t *sys, entity_t *player, e_list_t *mobs)
{
    while (mobs != NULL) {
        if (sprite_collide(player->sprite, mobs->entity->sprite)) {
            remove_life(sys);
        }
        mobs = mobs->next;
    }
}

int check_player_collisions(system_t *sys)
{
    e_list_t *player = get_entities(sys, PLAYER | VISIBLE);
    e_list_t *mobs = get_entities(sys, MOB | VISIBLE);

    while (player != NULL) {
        check_monsters(sys, player->entity, mobs);
        player = player->next;
    }
    clean_list(player);
    clean_list(mobs);
    return SUCCESS;
}
