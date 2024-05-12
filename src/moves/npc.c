/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** Functions related to Non Playable Caracters moves
*/

#include <SFML/Graphics.h>
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

static void try_mobs_move(int move, sokospot_t ***map, unsigned int line,
    unsigned int col)
{
    printf("moving\n");
    if (move == 0 && line > 0 && spot_available(map[line - 1][col])) {
        swap_struct(&map[line][col], &map[line - 1][col]);
        return;
    }
    if (move == 1 && spot_available(map[line][col + 1])) {
        swap_struct(&map[line][col], &map[line][col + 1]);
        return;
    }
    if (move == 2 && map[line + 1] && spot_available(map[line + 1][col])) {
        swap_struct(&map[line][col], &map[line + 1][col]);
        return;
    }
    if (move == 3 && col > 0 && spot_available(map[line][col - 1])) {
        swap_struct(&map[line][col], &map[line][col - 1]);
        return;
    }
}

bool set_sprite_pos_based_on_soko(sfSprite *sprite,
    int line, int col)
{
    sfVector2f pos = {0};

    pos.x = ((double)col / (double)MAP_WIDTH) * WIN_WIDTH;
    pos.y = ((double)line / (double)MAP_HEIGHT) * WIN_HEIGHT;
    if (sprite != NULL) {
        sfSprite_setPosition(sprite, pos);
        return true;
    }
    return false;
}

static void analyse_and_move(sokospot_t ***map, unsigned int line,
    unsigned int col)
{
    if (map[line][col] && map[line][col]->type == ENEMY) {
        try_mobs_move(random_nb(0, 4), map, line, col);
    }
}

static void enemy_sprite_move(sokospot_t ***map,
    unsigned int line, unsigned int col)
{
    if (map[line][col]->type == ENEMY) {
        set_sprite_pos_based_on_soko(map[line][col]->entity->sprite,
        line, col);
    }
}

void move_mobs(sokospot_t ***map)
{
    for (unsigned int line = 0; map[line]; line++) {
        for (unsigned int col = 0; map[line][col]; col++) {
            analyse_and_move(map, line, col);
        }
    }
    for (unsigned int line = 0; map[line]; line++) {
        for (unsigned int col = 0; map[line][col]; col++) {
            enemy_sprite_move(map, line, col);
        }
    }
}
