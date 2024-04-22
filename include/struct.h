/*
** EPITECH PROJECT, 2023
** MY RPG
** File description:
** Structures of the game
*/

#ifndef STRUCT_H
    #define STRUCT_H
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>

typedef struct parameters {
    sfRenderWindow* window;
    sfEvent event;
    sfSprite *background;
    sfClock *clock;
    sfMusic *music;
    char **map_array;
} parameters_t;

#endif
