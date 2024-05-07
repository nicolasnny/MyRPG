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

bool set_sprite_pos_based_on_soko(sfRenderWindow *win, sfSprite *sprite,
    int line, int col)
{
    sfVector2f pos = {0};
    sfVector2u win_size = sfRenderWindow_getSize(win);

    pos.x = ((double)col / (double)MAP_WIDTH) * win_size.x;
    pos.y = ((double)line / (double)MAP_HEIGHT) * win_size.y;
    if (sprite != NULL) {
        sfSprite_setPosition(sprite, pos);
	return true;
    }
    return false;
}

static void analyse_and_move(sokospot_t ***map, unsigned int line,
    unsigned int col, sfRenderWindow *win)
{
    if (map[line][col] && map[line][col]->type == ENEMY) {
	printf("moving smth\n");
	try_mobs_move(random_nb(0, 4), map, line, col);
	printf("before mobs move\n");
	if (map[line][col]->entity == NULL)
	    printf("becasue it is null| line: %d -> col: %d\n", line, col);
	else
	    printf("brahh\n");
	set_sprite_pos_based_on_soko
	    (win, map[line][col]->entity->sprite, line, col);
	printf("after sprite set\n");
    }
}

void move_mobs(sokospot_t ***map, sfRenderWindow *win)
{
    for (unsigned int line = 0; map[line]; line++) {
        for (unsigned int col = 0; map[line][col]; col++) {
            analyse_and_move(map, line, col, win);
        }
    }
}
