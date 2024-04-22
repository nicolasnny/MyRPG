/*
** EPITECH PROJECT, 2023
** MY_RPG
** File description:
** Main of my_rpg
*/

#include <stdlib.h>
#include <stdio.h>
#include "rpg.h"

static int loop(parameters_t *param)
{
    while (sfRenderWindow_isOpen(param->window)) {
        sfRenderWindow_pollEvent(param->window, &param->event);
        analyse_events(param);
        sfRenderWindow_display(param->window);
        sfRenderWindow_clear(param->window, sfWhite);
        display_sprites(param);
    }
    return SUCCESS;
}

int my_rpg(int ac, char **av)
{
    parameters_t param = {0};

    if (err_handling(ac, av) == ERROR) {
        return ERROR;
    }
    init_args(&param);
    if (param.map_array == NULL) {
        clean(&param);
        return ERROR;
    }
    loop(&param);
    clean(&param);
    return SUCCESS;
}
