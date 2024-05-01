/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** Functions related to Non Playable Caracters moves
*/

#include <unistd.h>
#include "rpg.h"

static bool spot_available(sokospot_t *spot)
{
    char type = '\0';

    if (spot == NULL) {
        return false;
    }
    type = spot->type;
    if (type == EMPTY) {
        return true;
    }
    return false;
}

static void try_player_move(int move, sokospot_t ***map, unsigned int line,
    unsigned int col)
{
    if (move == 0 && line > 0 && spot_available(map[line - 1][col])) {
        swap_struct(&map[line][col], &map[line - 1][col]);
        return;
    }
    if (move == 1 && spot_available(map[line][col + 1])) {
        swap_struct(&map[line][col], &map[line][col + 1]);
        return;
    }
    if (move == 2 && spot_available(map[line + 1][col])) {
        swap_struct(&map[line][col], &map[line + 1][col]);
        return;
    }
    if (move == 3 && col > 0 && spot_available(map[line][col - 1])) {
        swap_struct(&map[line][col], &map[line][col - 1]);
        return;
    }
}

void move_mobs(sokospot_t ***map)
{
    for (unsigned int line = 0; map[line]; line++) {
        for (unsigned int col = 0; map[line][col]; col++) {
            try_player_move(random_nb(0, 4), map, line, col);
        }
    }
}
