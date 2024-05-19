/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-nicolas.nunney
** File description:
** set_name.c
*/

#include <string.h>
#include "rpg.h"
#include "struct.h"
#include "associative.h"

void set_name(parameters_t *param, entity_t *entity, char *value)
{
    if (strcmp(value, "NULL") != 0) {
        entity->name = strdup(value);
    }
}
