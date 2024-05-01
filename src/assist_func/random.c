/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** Function for randoms
*/

#include <time.h>
#include <stdlib.h>
#include "rpg.h"

static int absolute(int nb)
{
    if (nb < 0) {
        return nb * -1;
    }
    return nb;
}

int random_nb(int a, int b)
{
    int small = a;

    if (b < a) {
        small = b;
    }
    srand(time(NULL));
    return small + (rand() % absolute(b - a));
}
