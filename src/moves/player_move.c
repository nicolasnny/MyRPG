/*
** EPITECH PROJECT, 2024
** MY_RPG
** File description:
** Functions related to player movements
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <stdio.h>
#include "rpg.h"
#include "struct.h"

static bool bump_time(void)
{
    static sfClock *clock = NULL;

    if (clock == NULL) {
        clock = sfClock_create();
        return true;
    }
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock))
            > BUMP_SOUND_RFRESH) {
        sfClock_restart(clock);
        return true;
    }
    return false;
}

static void move_not_possible(parameters_t *param)
{
    if (bump_time())
        sfSound_play(param->sounds_effect->bump);
}

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

void set_prev_pos(parameters_t *param, entity_t *player)
{
    sfSprite_setPosition(player->sprite, player->pos);
    sfView_setCenter(param->view, get_center(player->sprite));
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
    entity_t *player)
{
    sfVector2f map_size = get_map_size(param->sys);
    int x = 0;
    int y = 0;

    get_sprite_coords_on_sokomap(&map_size, player->sprite, &y, &x);
    if (x < 0 || y < 0 || x >= MAP_WIDTH || y >= MAP_HEIGHT) {
        dprintf(2, "Error: player pos can't be at this sokomap index\n");
        return;
    }
    if (!map[y][x])
        return;
    if (spot_available(map[y][x])) {
        player->pos = sfSprite_getPosition(player->sprite);
        return;
    }
    if (map[y][x]->type == OBSTACLE)
        move_not_possible(param);
    set_prev_pos(param, player);
}

entity_t *get_player_entity(system_t *sys)
{
    e_list_t *p_list = get_entities(sys, PLAYER);
    entity_t *e = NULL;

    if (p_list == NULL)
        return NULL;
    e = p_list->entity;
    clean_list(p_list);
    return e;
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

static void update_player_in_map
(parameters_t *param, entity_t *player, sfVector2f move)
{
    player->pos = sfSprite_getPosition(player->sprite);
    set_player_new_pos(param, move);
    move_in_array(param, param->map_array, player);
    refresh_inventory_pos(param->sys);
    refresh_heart_position(param->sys);
    set_lvl_pos(param->sys);
}

void move_player(parameters_t *param, sfIntRect *texture_pos,
    sfIntRect *idle_pos, sfVector2f *scale)
{
    entity_t *player = get_player_entity(param->sys);
    sfVector2f map_size = get_map_size(param->sys);
    sfVector2f move = {0};

    if (param->map_array == NULL || player == NULL)
        return;
    move = get_p_move_event(&map_size, player->sprite);
    if (move.x != 0.0 || move.y != 0.0) {
        idle_pos->top = PLAYER_IDLE_START;
        flip_sprite(move, player->sprite, scale);
        animate_player_walk(param, texture_pos, player->sprite);
        update_player_in_map(param, player, move);
        sfRenderWindow_setView(param->window, param->view);
    } else
        animate_idle(idle_pos, player->sprite);
    if (sfMouse_isButtonPressed(sfMouseLeft))
        animate_attack(param, texture_pos, player->sprite);
}
