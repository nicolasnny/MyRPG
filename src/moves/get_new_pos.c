/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** Function to get the player's new position
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "rpg.h"

sfVector2f get_p_move_event(sfSprite *player)
{
    sfVector2f move = {0};
    sfVector2f pos = sfSprite_getPosition(player);

    if ((sfKeyboard_isKeyPressed(sfKeyUp) ||
        sfKeyboard_isKeyPressed(sfKeyZ)) && pos.y > 0.0) {
        move.y -= PLAYER_SPEED;
    }
    if ((sfKeyboard_isKeyPressed(sfKeyRight) ||
        sfKeyboard_isKeyPressed(sfKeyD)) && pos.x < WIN_WIDTH) {
        move.x += PLAYER_SPEED;
    }
    if ((sfKeyboard_isKeyPressed(sfKeyLeft) ||
        sfKeyboard_isKeyPressed(sfKeyQ)) && pos.x > 0) {
        move.x -= PLAYER_SPEED;
    }
    if ((sfKeyboard_isKeyPressed(sfKeyDown) ||
        sfKeyboard_isKeyPressed(sfKeyS)) && pos.y < WIN_HEIGHT) {
        move.y += PLAYER_SPEED;
    }
    return move;
}

static void line_assist(sokospot_t ***map, int l, int *line, unsigned int *col)
{
    for (unsigned int i = 0; map[l][i]; i++) {
        if (map[l][i]->type == PLAYER_CHAR) {
            *line = l;
            *col = i;
            return;
        }
    }
}

void get_player_pos(sokospot_t ***map, int *line, unsigned int *col)
{
    *line = -1;
    for (int l = 0; map[l] != NULL; l++) {
        line_assist(map, l, line, col);
        if (*line != NOT_FOUND) {
            return;
        }
    }
}

sokospot_t *get_player_spot(sokospot_t ***map)
{
    unsigned int col = 0;

    for (int l = 0; map[l] != NULL; l++) {
        for (col = 0; map[l][col] && map[l][col]->type != PLAYER_CHAR; col++)
            continue;
        if (map[l][col])
            return map[l][col];
    }
    return NULL;
}

void set_player_first_pos(sfView *view, sokospot_t ***map)
{
    int line = 0;
    unsigned int col = 0;
    sfVector2f pos = {0};
    entity_t *player = get_player_spot(map)->entity;

    get_player_pos(map, &line, &col);
    if (line == NOT_FOUND) {
        dprintf(2, "Error: player not found in the map\n");
        return;
    }
    pos.x = ((double)col / (double)MAP_WIDTH) * WIN_WIDTH;
    pos.y = ((double)line / (double)MAP_HEIGHT) * WIN_HEIGHT;
    if (player != NULL) {
        sfSprite_setPosition(player->sprite, pos);
        pos = get_center(player->sprite);
        sfView_setCenter(view, pos);
    }
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
