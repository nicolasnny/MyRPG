/*
** EPITECH PROJECT, 2023
** MY_RADAR
** File description:
** Functions related to the displaying
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include "rpg.h"

void display_sprites(parameters_t *param)
{
    sfRenderWindow_drawSprite(param->window, param->background, NULL);
    sfRenderWindow_drawSprite(param->window, param->player->sprite, NULL);
}
