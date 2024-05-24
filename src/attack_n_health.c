/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-nicolas.nunney
** File description:
** attack_n_health.c
*/

#include <stdlib.h>
#include <string.h>
#include "rpg.h"
#include "struct.h"
#include "associative.h"

void set_attack(parameters_t *param, entity_t *entity, char *value)
{
    (void)param;
    if (strcmp(value, "NULL") == 0)
        return;
    entity->attack = atoi(value);
}

void set_health(parameters_t *param, entity_t *entity, char *value)
{
    (void)param;
    if (strcmp(value, "NULL") == 0)
        return;
    entity->health = atoi(value);
}
