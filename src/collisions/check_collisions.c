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

static bool check_monsters(system_t *sys, entity_t *player, e_list_t *mobs)
{
    while (mobs != NULL) {
        if (enemy_in_range(player, mobs->entity, ENEMY_ATTACK_RANGE)) {
            remove_life(sys);
            return true;
        }
        mobs = mobs->next;
    }
    return false;
}

int check_player_collisions(system_t *sys)
{
    e_list_t *player = get_entities(sys, PLAYER | VISIBLE);
    e_list_t *mobs = get_entities(sys, MOB | VISIBLE);
    e_list_t *m_head = mobs;
    e_list_t *p_head = player;
    static sfIntRect texture_pos =
        (sfIntRect){0, PLAYER_DAMMAGE_START, PLAYER_WIDTH, PLAYER_HEIGHT};

    while (player != NULL) {
        if (check_monsters(sys, player->entity, mobs)) {
            sfSprite_setTextureRect(player->entity->sprite, texture_pos);
        }
        player = player->next;
    }
    clean_list(p_head);
    clean_list(m_head);
    return SUCCESS;
}
