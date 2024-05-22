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

static void move_ennemy(sokospot_t ***map, entity_t *e, sfVector2f *player_pos)
{
    sfVector2f e_pos = sfSprite_getPosition(e->sprite);
    static sfVector2f move = {0};

    agro_player(e, player_pos);
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
            move_ennemy(map, list->entity, &pos);
        list = list->next;
    }
    reset_move_var(map);
}
