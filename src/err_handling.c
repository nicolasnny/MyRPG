/*
** EPITECH PROJECT, 2024
** MY_RPG
** File description:
** Error handling functions
*/

#include <stdio.h>
#include "rpg.h"

int err_handling(int ac, char **av)
{
    (void)av;
    if (ac != 1) {
        dprintf(2, "Error: Wrong number of arguments\n");
        return ERROR;
    }
    return SUCCESS;
}
