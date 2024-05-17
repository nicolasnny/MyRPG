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
        analyse_events(param);
        make_life(param);
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
    if (init_args(&param) == ERROR) {
        dprintf(2, "Error: initialisation failed\n");
        return ERROR;
    }
    if (param.map_array == NULL) {
        dprintf(2, "Error: param array initialisation failed\n");
        clean(&param);
        return ERROR;
    }
    loop(&param);
    clean(&param);
    return SUCCESS;
}
