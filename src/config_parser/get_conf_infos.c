/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-nicolas.nunney
** File description:
** get_conf_infos.c
*/

#include <string.h>
#include <stdlib.h>
#include "rpg.h"
#include "struct.h"
#include "my.h"
#include "associative.h"

static int get_compo(char *compo)
{
    for (int i = 0; compo_list[i].component; i++) {
        if (strcmp(compo, compo_list[i].component) == 0) {
            return compo_list[i].associate;
        }
    }
    return 0;
}

entity_t *entity_from_conf(char *compo, parameters_t *param)
{
    char *no_brackets = strdup_banned_chars(compo, " []");
    char **compo_array = my_str_to_word_array(no_brackets, "|");
    int component = 0;

    if (!compo_array)
        return NULL;
    for (int i = 0; compo_array[i]; i++) {
        component |= get_compo(compo_array[i]);
    }
    return create_entity(param->sys, component);
}

static void read_param(char *arg, entity_t *entity, parameters_t *param)
{
    char *no_space = strdup_banned_chars(arg, " ");
    char **line = my_str_to_word_array(no_space, "=");

    for (int i = 0; param_list[i].param; i++) {
        if (strcmp(line[0], param_list[i].param) == 0)
            param_list[i].exec(param, entity, line[1]);
    }
}

static void create(char **conf, int index, parameters_t *param)
{
    entity_t *entity = entity_from_conf(conf[index + 1], param);

    for (int i = index + 2; conf[i] &&
        strcmp(conf[i], CONFIG_ELEMENT_NAME) != 0; i++) {
        read_param(conf[i], entity, param);
    }
}

void create_from_conf(parameters_t *param)
{
    char **conf = get_config();

    if (!conf)
        return;
    for (int i = 0; conf[i]; i++) {
        if (strcmp(conf[i], CONFIG_ELEMENT_NAME) == 0) {
            create(conf, i, param);
        }
    }
    free_str_array(conf);
}
