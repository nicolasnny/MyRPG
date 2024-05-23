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
    set_view_on_player(param);
    refresh_inventory_pos(param->sys);
    sfView_setSize(param->view, (sfVector2f){DEFAULT_VIEW_SIZE_X,
        DEFAULT_VIEW_SIZE_Y});
    sfRenderWindow_setView(param->window, param->view);
    while (sfRenderWindow_isOpen(param->window) && param->game_state != QUIT) {
        sfView_setSize(param->view, (sfVector2f){DEFAULT_VIEW_SIZE_X,
            DEFAULT_VIEW_SIZE_Y});
        sfRenderWindow_setView(param->window, param->view);
        window_events(param, MOB);
        make_life(param);
        display_entities(param, VISIBLE);
        sfRenderWindow_display(param->window);
        sfRenderWindow_clear(param->window, sfWhite);
    }
    return SUCCESS;
}

static void game_launcher(parameters_t *param)
{
    int start = start_menu(param, NULL, true);

    if (start == ERROR)
        return;
    sfRenderWindow_setView(param->window, param->view);
    if (param->game_state == PLAY) {
        loop(param);
    }
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
    loading_screen_loop(&param);
    if (sfRenderWindow_isOpen(param.window))
        game_launcher(&param);
    clean(&param);
    return SUCCESS;
}
