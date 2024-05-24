/*
** EPITECH PROJECT, 2024
** MY_RPG
** File description:
** Main
*/

#include "rpg.h"
#include "my.h"

int main(int ac, char **av, char **env)
{
    if (!env || my_strstrlen(env) == 0)
        return ERROR;
    return my_rpg(ac, av);
}
