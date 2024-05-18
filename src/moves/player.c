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

static void move_in_array(parameters_t *param, sokospot_t ***map,
    sfSprite *player)
{
    sfVector2f pos = get_center(player);
    int l = 0;
    unsigned int col = 0;
    sokospot_t *player_spot = get_player_pos_and_entity(map, &l, &col);
    sfVector2u w_size = sfRenderWindow_getSize(param->window);
    int x = (int)(MAP_WIDTH * pos.x / w_size.x);
    int y = (int)(MAP_HEIGHT * pos.y / w_size.y);

    if (x < 0 || y < 0) {
        dprintf(2, "Error: player pos can't be at this sokomap index\n");
        return;
    }
    printf("before spot availabe-> {x: %d, y: %d}\n", x, y);
    if (spot_available(map[x][y]) || map[x][y]->type == PLAYER_CHAR) {
        printf("before swapping struct\n");
        swap_struct(&map[x][y], &player_spot);
        return;
    }
    printf("before check reason\n");
    if (map[x][y]->type == OBSTACLE)
        move_not_possible();
    printf("before setting back old pos\n");
    set_player_first_pos(param->view, map);
}

sfSprite *get_player(system_t *sys)
{
    e_list_t *p_list = get_entities(sys, PLAYER);
    sfSprite *s = NULL;

    if (p_list == NULL)
        return NULL;
    s = p_list->entity->sprite;
    clean_list(p_list);
    return s;
}

void move_player(parameters_t *param)
{
    printf("in move player\n");
    static sfClock *clock = NULL;
    sfVector2f move = {0};
    sfSprite *player = get_player(param->sys);

    if (param->map_array == NULL || player == NULL) {
        return;
    }
    if (clock == NULL)
        clock = sfClock_create();
    printf("in get player mov");
    move = get_p_move_event(player);
    printf("before move check: {%f, %f}\n", move.x, move.y);
    if (move.x != 0.0 || move.y != 0.0) {
        set_player_new_pos(param, move);
        if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) > 0) {
            move_in_array(param, param->map_array, player);
            sfClock_restart(clock);
        }
        sfRenderWindow_setView(param->window, param->view);
        set_inventory_pos(param->sys);
    }
    printf("func end\n");
}
