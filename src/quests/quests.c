/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-nicolas.nunney
** File description:
** quests.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "struct.h"
#include "rpg.h"
#include "associative.h"

static void reset_trigger(parameters_t *param)
{
    e_list_t *triggers = get_entities(param->sys, QUEST_TRIGGER);

    while (triggers) {
        unset_entity(param->sys, triggers->entity, VISIBLE);
        triggers = triggers->next;
    }
}

static entity_t *disp_trigger(sfVector2f *npc_pos, parameters_t *param)
{
    e_list_t *triggers = get_entities(param->sys, QUEST_TRIGGER);
    sfVector2f trigger_pos = sfSprite_getPosition(triggers->entity->sprite);
    double dist = get_distance_bewteen_pos(npc_pos, &trigger_pos);
    double tmp_dist = 0.0;
    entity_t *final_trigger = triggers->entity;

    while (triggers) {
        trigger_pos = sfSprite_getPosition(triggers->entity->sprite);
        tmp_dist = get_distance_bewteen_pos(&trigger_pos, npc_pos);
        if (tmp_dist < dist) {
            final_trigger = triggers->entity;
            dist = tmp_dist;
        }
        triggers = triggers->next;
    }
    set_entity(final_trigger, param->sys, VISIBLE);
    return final_trigger;
}

static bool check_npc_quest(entity_t *npc, entity_t *player,
    parameters_t *param)
{
    sfVector2f npc_pos = sfSprite_getPosition(npc->sprite);
    sfVector2f player_pos = sfSprite_getPosition(player->sprite);
    double dist = get_distance_bewteen_pos(&npc_pos, &player_pos);
    entity_t *trigger = NULL;

    if (dist < DIST_TO_QUEST) {
        trigger = disp_trigger(&npc_pos, param);
        if (sfKeyboard_isKeyPressed(sfKeyEnter)) {
            set_entity(npc, param->sys, BOX);
            trigger->clicked(param, NULL, false);
        }
    } else {
        reset_trigger(param);
        unset_entity(param->sys, npc, BOX);
    }
    return false;
}

int reset_quest(parameters_t *param, entity_t *entity, bool state)
{
    e_list_t *quests = get_entities(param->sys, QUEST);
    e_list_t *temp = quests;
    entity_t *reset_button = get_entity_by_name(param->sys, "reset_quest");

    while (temp) {
        unset_entity(param->sys, temp->entity, VISIBLE);
        temp = temp->next;
    }
    unset_entity(param->sys, reset_button, VISIBLE);
    clean_list(quests);
    param->actual_quest = NULL;
    (void)entity;
    (void)state;
    return SUCCESS;
}

void check_quest(parameters_t *param)
{
    e_list_t *npc_s = get_entities(param->sys, NPC);
    e_list_t *player = get_entities(param->sys, PLAYER);
    e_list_t *temp_npc_s = npc_s;

    if (!npc_s || !player) {
        printf("no quest to attribute\n");
        return;
    }
    while (temp_npc_s) {
        check_npc_quest(temp_npc_s->entity, player->entity, param);
        temp_npc_s = temp_npc_s->next;
    }
    clean_list(npc_s);
    clean_list(player);
    if (param->actual_quest && param->actual_quest(param))
        reset_quest(param, NULL, false);
    return;
}
