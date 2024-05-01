/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** Function to trigger game events
*/

#include "rpg.h"

void make_life(parameters_t *param)
{
    move_mobs(param->map_array);
}
