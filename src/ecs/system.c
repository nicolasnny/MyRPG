/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-nicolas.nunney
** File description:
** system.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "rpg.h"

system_t *create_system(void)
{
    system_t *new_system = malloc(sizeof(system_t));

    if (new_system == NULL) {
        perror("systemp malloc failed");
        return NULL;
    }
    new_system->e_list = NULL;
    //new_system->component = malloc(sizeof(e_list_t *));
    for (unsigned int n = 1; 1 << n < __END__; n++) {
        new_system->component[1 << n] = NULL;
    }
    return new_system;
}
