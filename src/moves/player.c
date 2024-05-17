/*
** EPITECH PROJECT, 2024
** MY_RPG
** File description:
** Functions related to player movements
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include "rpg.h"
#include "struct.h"

static int get_p_move_event(void)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp) || sfKeyboard_isKeyPressed(sfKeyZ)) {
        return sfKeyUp;
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight) ||
        sfKeyboard_isKeyPressed(sfKeyD)) {
        return sfKeyRight;
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft) ||
        sfKeyboard_isKeyPressed(sfKeyQ)) {
        return sfKeyLeft;
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown) ||
        sfKeyboard_isKeyPressed(sfKeyS)) {
        return sfKeyDown;
    }
    return NO_ARROW_KEY_PRESSED;
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

static sokospot_t *get_player_pos_and_entity(sokospot_t ***map, int *line,
    unsigned int *col)
{
    *line = -1;
    for (int l = 0; map[l] != NULL; l++) {
        line_assist(map, l, line, col);
        if (*line != NOT_FOUND) {
            return map[*line][*col];
        }
    }
    return NULL;
}

void swap_struct(sokospot_t **current, sokospot_t **target)
{
    sokospot_t *tmp = *current;

    if (((*target)->moved_in_frame || (*current)->moved_in_frame)
        && (*current)->type != PLAYER_CHAR) {
        return;
    }
    (*current)->moved_in_frame = true;
    (*target)->moved_in_frame = true;
    *current = *target;
    *target = tmp;
}

static void move_not_possible(void)
{
    printf("** bump sound **\n");
}

static bool spot_available(sokospot_t *spot)
{
    char type = '\0';

    if (spot == NULL) {
        return false;
    }
    type = spot->type;
    if (type == EMPTY || type == NPC_LIMIT) {
        return true;
    }
    return false;
}

static void try_player_move(int move, sokospot_t ***map, int line,
    unsigned int col)
{
    if (move == sfKeyUp && line > 0 && spot_available(map[line - 1][col])) {
        swap_struct(&map[line][col], &map[line - 1][col]);
        return;
    }
    if (move == sfKeyRight && spot_available(map[line][col + 1])) {
        swap_struct(&map[line][col], &map[line][col + 1]);
        return;
    }
    if (move == sfKeyDown && map[line + 1] && spot_available(map[line + 1][col])) {
        swap_struct(&map[line][col], &map[line + 1][col]);
        return;
    }
    if (move == sfKeyLeft && col > 0 && spot_available(map[line][col - 1])) {
        swap_struct(&map[line][col], &map[line][col - 1]);
        return;
    }
    move_not_possible();
}

static void move_in_array(sokospot_t ***map, int move)
{
    int line = 0;
    unsigned int col = 0;

    get_player_pos_and_entity(map, &line, &col);
    if (line == NOT_FOUND) {
        dprintf(2, "Error: player not found in the map\n");
        return;
    }
    try_player_move(move, map, line, col);
}

void set_player_new_pos(sfView *view, sokospot_t ***map)
{
    int line = 0;
    unsigned int col = 0;
    sfVector2f pos = {0};
    entity_t *player = get_player_pos_and_entity(map, &line, &col)->entity;

    if (line == NOT_FOUND) {
        dprintf(2, "Error: player not found in the map\n");
        return;
    }
    pos.x = ((double)col / (double)MAP_WIDTH) * WIN_WIDTH;
    pos.y = ((double)line / (double)MAP_HEIGHT) * WIN_HEIGHT;
    if (player != NULL) {
        sfSprite_setPosition(player->sprite, pos);
        pos.x += sfSprite_getGlobalBounds(player->sprite).width / 2;
        pos.y += sfSprite_getGlobalBounds(player->sprite).height / 2;
        sfView_setCenter(view, pos);
    }
}

void move_player(parameters_t *param)
{
    int move = 0;

    if (param->map_array == NULL) {
        return;
    }
    move = get_p_move_event();
    if (move != NO_ARROW_KEY_PRESSED) {
        move_in_array(param->map_array, move);
        set_player_new_pos(param->view, param->map_array);
        sfRenderWindow_setView(param->window, param->view);
        set_inventory_pos(param->sys);
    }
}
