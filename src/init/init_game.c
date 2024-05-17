/*
** EPITECH PROJECT, 2024
** MY_RPG
** File description:
** Functions related to my_rpg initialinisation
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include "rpg.h"

static sfView *create_view(void)
{
    sfView *view = sfView_create();
    sfVector2f pos = {DEFAULT_VIEW_X, DEFAULT_VIEW_Y};

    if (view == NULL) {
        dprintf(2, "Error: view initialisation failed\n");
        return NULL;
    }
    (void)pos;
    sfView_setSize(view, (sfVector2f){250 * 2, 144 * 2});
    return view;
}

static int finish_initialisation(parameters_t *param)
{
    if (init_inventory(param) == ERROR) {
        return ERROR;
    }
    return SUCCESS;
}

int init_args(parameters_t *param)
{
    sfVideoMode video_mode = {WIN_WIDTH, WIN_HEIGHT, WIN_PIX_NB};

    param->window = sfRenderWindow_create(video_mode, "My RPG",
        sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(param->window, FPS);
    param->sys = create_system();
    param->view = create_view();
    if (param->sys == NULL || param->window == NULL || param->view == NULL) {
        return ERROR;
    }
    sfRenderWindow_setView(param->window, param->view);
    if (create_entity(param->sys, MAP_SPRITE_PATH, NULL, VISIBLE) == NULL) {
        return ERROR;
    }
    param->map_array = get_map(MAP_ARRAY_PATH, param->sys);
    if (param->map_array == NULL) {
        return ERROR;
    }
    set_player_new_pos(param->view, param->map_array);
    return finish_initialisation(param);
}
