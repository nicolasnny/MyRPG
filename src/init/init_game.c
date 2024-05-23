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

sfView *create_view(void)
{
    sfView *view = sfView_create();

    if (view == NULL) {
        dprintf(2, "Error: view initialisation failed\n");
        return NULL;
    }
    return view;
}

int init_args(parameters_t *param)
{
    sfVideoMode video_mode = {WIN_WIDTH, WIN_HEIGHT, WIN_PIX_NB};

    param->window = sfRenderWindow_create(video_mode, "My RPG",
        sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(param->window, FPS);
    param->sys = create_system();
    if (param->sys == NULL || param->window == NULL) {
        return ERROR;
    }
    create_from_conf(param);
    param->map_array = get_map(MAP_ARRAY_PATH);
    if (param->map_array == NULL)
        return ERROR;
    param->game_state = PAUSE;
    param->view = create_view();
    param->sound_volume = 100.0;
    param->music = NULL;
    return SUCCESS;
}
