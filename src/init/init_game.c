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

/*static int set_background(parameters_t *param)
{
    sfTexture *texture = NULL;

    param->background = sfSprite_create();
    if (param->background == NULL) {
        dprintf(2, "Error: unable to create the background sprite\n");
        return ERROR;
    }
    texture = sfTexture_createFromFile(MAP_SPRITE_PATH, NULL);
    if (texture == NULL){
        dprintf(2, "Error: unable to load \"%s\" as background texture\n",
        MAP_SPRITE_PATH);
        sfSprite_destroy(param->background);
        return ERROR;
    }
    sfSprite_setTexture(param->background, texture, sfFalse);
    return SUCCESS;
}

static int init_player(parameters_t *param)
{
    entity_t *e = create_entity(param->sys, PLAYER_SPRITE_PATH, NULL);

    if (e == NULL) {
        return ERROR;
    }
    if (set_entity(e, param->sys, PLAYER | VISIBLE)) {
        return ERROR;
    }
    return SUCCESS;
}*/

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
