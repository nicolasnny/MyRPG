/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** Functions related to Non Playable Caracters moves
*/

#include <SFML/Graphics.h>
#include <math.h>
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

bool sprite_in_view(sfView *v, sfSprite *s)
{
    sfVector2f v_pos = {0};
    sfVector2f v_size = {0};
    sfVector2f s_pos = {0};

    if (v == NULL || s == NULL)
        return false;
    v_pos = sfView_getCenter(v);
    v_size = sfView_getSize(v);
    s_pos = get_center(s);
    if (s_pos.x < v_pos.x - v_size.x / 2 || s_pos.x > v_pos.x + v_size.x / 2)
        return false;
    if (s_pos.y < v_pos.y - v_size.y / 2 || s_pos.y > v_pos.y + v_size.y / 2)
        return false;
    return true;
}

static void check_move_possible(parameters_t *param, sokospot_t ***map,
    entity_t *e)
{
    int line = 0;
    int col = 0;
    sfVector2f map_size = get_map_size(param->sys);

    get_sprite_coords_on_sokomap(&map_size, e->sprite, &line, &col);
    if (line < 0 || col < 0 || line >= MAP_HEIGHT || col >= MAP_WIDTH ||
        !spot_available(map[line][col])) {
        sfSprite_setPosition(e->sprite, e->pos);
        return;
    }
    e->pos = sfSprite_getPosition(e->sprite);
}

static void move_enemy(parameters_t *param,
    sokospot_t ***map, entity_t *e, sfVector2f *player_pos)
{
    sfVector2f e_pos = get_center(e->sprite);
    sfVector2f v_dir = {player_pos->x - e_pos.x, player_pos->y - e_pos.y};
    float n = sqrt(v_dir.x * v_dir.x + v_dir.y * v_dir.y);

    e->pos = e_pos;
    v_dir.x = v_dir.x / n * MOBS_SPEED;
    v_dir.y = v_dir.y / n * MOBS_SPEED;
    sfSprite_move(e->sprite, v_dir);
    check_move_possible(param, map, e);
}

void move_mobs(parameters_t *param, sokospot_t ***map)
{
    e_list_t *list = get_entities(param->sys, MOB);
    sfSprite *player = get_player(param->sys);
    sfVector2f pos = {0};

    if (player == NULL)
        return;
    pos = sfSprite_getPosition(player);
    while (list) {
        if (sprite_in_view(param->view, list->entity->sprite))
            move_enemy(param, map, list->entity, &pos);
        list = list->next;
    }
}
