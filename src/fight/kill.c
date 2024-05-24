/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** Functions related to killing system
*/

#include <stdbool.h>
#include <stdio.h>
#include "rpg.h"

static void take_damage(system_t *sys, entity_t *enemy, entity_t *player)
{
    enemy->health -= player->attack;
    if (enemy->health <= 0) {
        if (enemy->name)
                printf("You killed %s !\n", enemy->name);
        unset_entity(sys, enemy, VISIBLE);
        move_lvl_rect(sys);
    }
}

int kill_entity(parameters_t *param, entity_t *entity, bool state)
{
    e_list_t *player = get_entities(param->sys, PLAYER | VISIBLE);
    e_list_t *tmp_mob = get_entities(param->sys, MOB | VISIBLE);

    (void)state;
    if (player == NULL || entity == NULL)
        return ERROR;
    if (entity_in_list(tmp_mob, entity) &&
        enemy_in_range(player->entity, entity, PLAYER_ATTACK_RANGE)) {
        sound_design
        sfSound_play(param->sounds_effect->enemy_damage);
        unset_entity(param->sys, entity, VISIBLE);
        take_damage(param->sys, tmp_mob->entity, player->entity);
        clean_list(player);
        clean_list(tmp_mob);
        return 1;
    }
    clean_list(player);
    clean_list(tmp_mob);
    return SUCCESS;
}
