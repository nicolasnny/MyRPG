/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-nicolas.nunney
** File description:
** system.c
*/

#include <stdlib.h>
#include "struct.h"
#include "rpg.h"

system_t *create_system(void)
{
    system_t *new_system = malloc(sizeof(system_t));

    new_system->e_list = NULL;
    for (unsigned int n = 1; n < __END__; n <<= 2) {
        new_system->component[n] = NULL;
    }
    return new_system;
}
