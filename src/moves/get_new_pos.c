/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** Function to get the player's new position
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include <math.h>
#include "rpg.h"

sfVector2f get_p_move_event(sfVector2f *map_size, sfSprite *player)
{
    sfVector2f move = {0};
    sfFloatRect p_rect = sfSprite_getGlobalBounds(player);

    if ((sfKeyboard_isKeyPressed(sfKeyUp) ||
        sfKeyboard_isKeyPressed(sfKeyZ)) && p_rect.top > 0.0)
        move.y -= PLAYER_SPEED;
    if ((sfKeyboard_isKeyPressed(sfKeyRight)
        || sfKeyboard_isKeyPressed(sfKeyD))
        && p_rect.left + p_rect.width < map_size->x)
        move.x += PLAYER_SPEED;
    if ((sfKeyboard_isKeyPressed(sfKeyLeft) ||
        sfKeyboard_isKeyPressed(sfKeyQ)) && p_rect.left > 0)
        move.x -= PLAYER_SPEED;
    if ((sfKeyboard_isKeyPressed(sfKeyDown) || sfKeyboard_isKeyPressed(sfKeyS))
        && p_rect.top + p_rect.height < map_size->y)
        move.y += PLAYER_SPEED;
    return move;
}

void set_player_new_pos(parameters_t *param, sfVector2f move)
{
    e_list_t *p_list = get_entities(param->sys, PLAYER | VISIBLE);
    sfSprite *player = NULL;

    if (p_list == NULL) {
        return;
    }
    player = p_list->entity->sprite;
    sfSprite_move(player, move);
    sfView_setCenter(param->view, get_center(player));
    clean_list(p_list);
}

bool get_sprite_coords_on_sokomap(sfVector2f *map_size, sfSprite *s,
    int *line, int *col)
{
    sfVector2f pos = get_center(s);

    if (s == NULL || line == NULL || col == NULL || map_size == NULL)
        return false;
    *col = (int)round(MAP_WIDTH * pos.x / map_size->x);
    *line = (int)round(MAP_HEIGHT * pos.y / map_size->y);
    return true;
}
