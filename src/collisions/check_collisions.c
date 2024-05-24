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

bool check_monsters(parameters_t *param, entity_t *player)
{
    e_list_t *mobs = get_entities(param->sys, MOB | VISIBLE);

    while (mobs != NULL) {
           // printf("First name: %s\n", mobs->entity->name);
        if (enemy_in_range(player, mobs->entity, ENEMY_ATTACK_RANGE)) {
            remove_life(param->sys);
            //  printf("name: %s\n", mobs->entity->name);
            anime_enemy_fight(param, mobs->entity);
            return true;
        } else
            anime_enemy_walk(param, mobs->entity);
        mobs = mobs->next;
    }
    clean_list(mobs);
    return false;
}

int check_player_collisions(parameters_t *param)
{
    e_list_t *player = get_entities(param->sys, PLAYER | VISIBLE);
    e_list_t *p_head = player;
    static sfIntRect texture_pos =
        (sfIntRect){0, PLAYER_DAMMAGE_START, PLAYER_WIDTH, PLAYER_HEIGHT};
    sfInt32 time = 0;

    while (player != NULL) {
        time = (sfTime_asMilliseconds(sfClock_getElapsedTime(param->clock)) -
        sfTime_asMilliseconds(player->entity->entity_time));
        if (check_monsters(param, player->entity)) {
            sfSprite_setTextureRect(player->entity->sprite, texture_pos);
        }
        if (check_monsters(param, player->entity) && time >= REFRESH_SPEED_DAMAGE) {
            sfSound_play(param->sounds_effect->player_damage);
            player->entity->entity_time = sfClock_getElapsedTime(param->clock);
        }
        player = player->next;
    }
    clean_list(p_head);
    return SUCCESS;
}
