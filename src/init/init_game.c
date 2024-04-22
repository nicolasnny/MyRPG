/*
** EPITECH PROJECT, 2024
** MY_RPG
** File description:
** Functions related to my_rpg initialinisation
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include "rpg.h"

void init_args(parameters_t *param)
{
    sfVideoMode video_mode = {WIN_WIDTH, WIN_HEIGHT, WIN_PIX_NB};
    sfTexture *texture = sfTexture_createFromFile(MAP_SPRITE_PATH, NULL);

    param->background = sfSprite_create();
    if (texture != NULL && param->background != NULL) {
        sfSprite_setTexture(param->background, texture, sfFalse);
    } else if (param->background == NULL) {
        dprintf(2, "Error: unable to create the background sprite\n");
    } else {
        dprintf(2, "Error: unable to load \"%s\" as background texture\n", MAP_SPRITE_PATH);
    }
    param->window = sfRenderWindow_create(video_mode, "My RPG",
        sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(param->window, FPS);
}
