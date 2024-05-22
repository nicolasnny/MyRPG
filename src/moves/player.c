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

void set_prev_pos(parameters_t *param, sfSprite *player,
    sokospot_t *player_spot)
{
    sfSprite_setPosition(player, player_spot->last_pos);
    sfView_setCenter(param->view, get_center(player));
}

sfVector2f get_map_size(system_t *sys)
{
    entity_t *map = get_entity_by_name(sys, MAP_NAME);
    sfFloatRect map_rect = {0};
    sfVector2f map_size = {0};

    if (map != NULL) {
        map_rect = sfSprite_getGlobalBounds(map->sprite);
        map_size.x = map_rect.width;
        map_size.y = map_rect.height;
        return map_size;
    }
    map_size.x = WIN_WIDTH;
    map_size.y = WIN_HEIGHT;
    return map_size;
}

static void move_in_array(parameters_t *param, sokospot_t ***map,
    sfSprite *player)
{
    sokospot_t *player_spot = get_player_spot(map);
    sfVector2f map_size = get_map_size(param->sys);
    int x = 0;
    int y = 0;

    get_sprite_coords_on_sokomap(&map_size, player, &y, &x);
    if (x < 0 || y < 0 || x >= MAP_WIDTH || y >= MAP_HEIGHT) {
        dprintf(2, "Error: player pos can't be at this sokomap index\n");
        return;
    }
    if (!map[y][x] || map[y][x]->type == PLAYER_CHAR)
        return;
    if (spot_available(map[y][x]) || map[y][x]->type == PLAYER_CHAR) {
        if (map[y][x]->type != PLAYER_CHAR)
            swap_struct(&player_spot, &map[y][x]);
        return;
    }
    if (map[y][x]->type == OBSTACLE)
        move_not_possible();
    set_prev_pos(param, player, player_spot);
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
    sfVector2f move = {0};
    sfSprite *player = get_player(param->sys);
    sfVector2f map_size = get_map_size(param->sys);

    if (param->map_array == NULL || player == NULL)
        return;
    move = get_p_move_event(&map_size, player);
    if (move.x != 0.0 || move.y != 0.0) {
        get_player_spot(param->map_array)->last_pos =
            sfSprite_getPosition(player);
        set_player_new_pos(param, move);
        move_in_array(param, param->map_array, player);
        sfRenderWindow_setView(param->window, param->view);
        refresh_inventory_pos(param->sys);
    }
}
