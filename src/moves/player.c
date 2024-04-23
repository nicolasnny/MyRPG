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
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        return sfKeyUp;
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        return sfKeyRight;
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        return sfKeyLeft;
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        return sfKeyDown;
    }
    return NO_ARROW_KEY_PRESSED;
}

static void line_assist(char **map, int l, int *line, unsigned int *col)
{
    for (unsigned int i = 0; map[l][i]; i++) {
        if (map[l][i] == PLAYER) {
            *line = l;
            *col = i;
            return;
        }
    }
}

static int get_player_pos(char **map, int *line, unsigned int *col)
{
    *line = -1;
    for (int l = 0; map[l]; l++) {
        line_assist(map, l, line, col);
        if (*line != NOT_FOUND) {
            return SUCCESS;
        }
    }
    return ERROR;
}

static void swap_player(char *current, char *target)
{
    char tmp = *current;

    *current = *target;
    *target = tmp;
}

static void move_not_possible(void)
{
    printf("** bump sound **\n");
}

static void try_player_move(int move, char **map, int line, unsigned int col)
{
    if (move == sfKeyUp && line > 0 && map[line - 1][col] == EMPTY) {
        swap_player(&map[line][col], &map[line - 1][col]);
        return;
    }
    if (move == sfKeyRight && map[line][col + 1] != '\0' &&
        map[line][col + 1] == EMPTY) {
        swap_player(&map[line][col], &map[line][col + 1]);
        return;
    }
    if (move == sfKeyDown && map[line + 1] != NULL &&
        map[line + 1][col] == EMPTY) {
        swap_player(&map[line][col], &map[line + 1][col]);
        return;
    }
    if (move == sfKeyLeft && col > 0 && map[line][col - 1] == EMPTY) {
        swap_player(&map[line][col], &map[line][col - 1]);
        return;
    }
    move_not_possible();
}

static void move_in_array(char **map, int move)
{
    int line = 0;
    unsigned int col = 0;

    get_player_pos(map, &line, &col);
    if (line == NOT_FOUND) {
        dprintf(2, "Error: player not found in the map\n");
        return;
    }
    try_player_move(move, map, line, col);
}

void set_player_new_pos(parameters_t *param, char **map)
{
    int line = 0;
    unsigned int col = 0;
    sfVector2f pos = {0};
    sfVector2u win_size = sfRenderWindow_getSize(param->window);

    get_player_pos(map, &line, &col);
    if (line == NOT_FOUND) {
        dprintf(2, "Error: player not found in the map\n");
        return;
    }
    pos.x = ((double)col / (double)MAP_WIDTH) * win_size.x;
    pos.y = ((double)line / (double)MAP_HEIGHT) * win_size.y;
    sfSprite_setPosition(param->player->sprite, pos);
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
        set_player_new_pos(param, param->map_array);
    }
}
