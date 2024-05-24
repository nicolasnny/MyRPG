/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** Functions to check collisions by hit box
*/

#include <SFML/Graphics.h>
#include <unistd.h>
#include <stdio.h>
#include "rpg.h"
#include "struct.h"

bool check_monsters(parameters_t *param, entity_t *player)
{
    e_list_t *mobs = get_entities(param->sys, MOB | VISIBLE);
    bool flag = false;

    while (mobs != NULL) {
        if (enemy_in_range(player, mobs->entity, ENEMY_ATTACK_RANGE)) {
            remove_life(param->sys);
            anime_enemy_fight(param, mobs->entity);
            flag = true;
        } else
            anime_enemy_walk(param, mobs->entity);
        mobs = mobs->next;
    }
    clean_list(mobs);
    return flag;
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
        if (check_monsters(param, player->entity))
            sfSprite_setTextureRect(player->entity->sprite, texture_pos);
        if (check_monsters(param, player->entity) &&
            time >= REFRESH_SPEED_DAMAGE) {
            sfSound_play(param->sounds_effect->player_damage);
            player->entity->entity_time = sfClock_getElapsedTime(param->clock);
        }
        player = player->next;
    }
    clean_list(p_head);
    return SUCCESS;
}
