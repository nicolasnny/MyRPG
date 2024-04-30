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

int init_args(parameters_t *param)
{
    sfVideoMode video_mode = {WIN_WIDTH, WIN_HEIGHT, WIN_PIX_NB};

    param->window = sfRenderWindow_create(video_mode, "My RPG",
        sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(param->window, FPS);
    param->map_array = get_map(MAP_ARRAY_PATH);
    param->sys = create_system();
    if (param->sys == NULL) {
        return ERROR;
    }
    if (create_entity(param->sys, MAP_SPRITE_PATH, NULL, VISIBLE) == NULL) {
        return ERROR;
    }
    if (create_entity(param->sys, PLAYER_SPRITE_PATH,
        NULL, VISIBLE | PLAYER) == NULL) {
        return ERROR;
        }
    return SUCCESS;
}
