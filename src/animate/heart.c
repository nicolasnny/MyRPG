/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** Functions related to heart texture rectangles
*/

#include "rpg.h"

void move_heart_rect(sfSprite *s)
{
    sfIntRect rect = sfSprite_getTextureRect(s);

    rect.left += rect.width;
    if (rect.left >= HEART_WIDTH)
        rect.left = 0;
    sfSprite_setTextureRect(s, rect);
}