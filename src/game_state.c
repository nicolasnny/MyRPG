/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-nicolas.nunney
** File description:
** game_state.c
*/

#include "rpg.h"
#include "struct.h"

int set_to_play(parameters_t *param, system_t *system, entity_t *entity,
    bool clicked)
{
    if (clicked) {
        param->game_state = PLAY;
    }
    return SUCCESS;
}

int set_to_pause(parameters_t *param, system_t *system, entity_t *entity,
    bool clicked)
{
    if (clicked) {
        param->game_state = PAUSE;
    }
    return SUCCESS;
}

int set_to_quit(parameters_t *param, system_t *system, entity_t *entity,
    bool clicked)
{
    if (clicked) {
        param->game_state = QUIT;
    }
    return SUCCESS;
}