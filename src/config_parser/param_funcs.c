/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-nicolas.nunney
** File description:
** param_funcs.c
*/

#include <stdlib.h>
#include <string.h>
#include "rpg.h"
#include "struct.h"
#include "associative.h"
#include "my.h"

double *get_double_array(char *arg)
{
    char *no_brackets = strdup_banned_chars(arg, " {}");
    char **arg_array = NULL;
    double *values = NULL;

    if (!no_brackets) {
        return NULL;
    }
    if (strcmp(arg, "NULL") == 0) {
        free(no_brackets);
        free(values);
        return NULL;
    }
    arg_array = my_str_to_word_array(no_brackets, ",");
    values = calloc(my_strstrlen(arg_array), sizeof(double));
    for (int i = 0; arg_array[i]; i++)
        values[i] = atof(arg_array[i]);
    return values;
}

int *get_int_array(char *arg)
{
    char *no_brackets = strdup_banned_chars(arg, " {}");
    char **arg_array = NULL;
    int *values = NULL;
    int i = 0;

    if (!no_brackets)
        return NULL;
    if (strcmp(arg, "NULL") == 0) {
        free(no_brackets);
        free(values);
        return NULL;
    }
    arg_array = my_str_to_word_array(no_brackets, ",");
    values = calloc(my_strstrlen(arg_array), sizeof(int));
    for (i = 0; arg_array[i]; i++)
        values[i] = atoi(arg_array[i]);
    values[i] = -1;
    return values;
}

static int get_arg_len(char *arg)
{
    char *no_brackets = strdup_banned_chars(arg, " {}");
    char **arg_array = NULL;

    if (no_brackets == NULL)
        return 0;
    arg_array = my_str_to_word_array(no_brackets, ",");
    if (arg_array == NULL)
        return 0;
    return my_strstrlen(arg_array);
}

void set_texture(parameters_t *param, entity_t *entity, char *value)
{
    char **args = my_str_to_word_array(value, ";");
    int *rect = NULL;
    sfIntRect texture_rect = (sfIntRect){0, 0, 0, 0};
    bool rect_input = false;

    if (args[1]) {
        rect = get_int_array(args[1]);
    }
    if (rect && get_arg_len(args[1]) == 4) {
        texture_rect.left = rect[0];
        texture_rect.top = rect[1];
        texture_rect.width = rect[2];
        texture_rect.height = rect[3];
        rect_input = true;
    }
    if (strcmp("NULL", value) != 0) {
        if (entity->sprite && rect_input)
            set_sprite_texture(entity, args[0], &texture_rect);
        if (entity->sprite && !rect_input)
            set_sprite_texture(entity, args[0], (sfIntRect *)rect);
        if (entity->rect)
            set_rectangle_texture(entity, args[0], NULL);
    }
    free_str_array(args);
    (void)param;
}

static void run_func(char *func, parameters_t *param, entity_t *entity)
{
    for (int i = 0; func_list[i].func_name; i++) {
        if (strcmp(func_list[i].func_name, func) == 0)
            func_list[i].function(param, entity, true);
    }
}

void run_on_start(parameters_t *param, entity_t *entity, char *value)
{
    char **func_list = my_str_to_word_array(value, ";");

    for (int i = 0; func_list[i]; i++) {
        run_func(func_list[i], param, entity);
    }
}
