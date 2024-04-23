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

typedef struct player_s {
    unsigned int lvl;
    unsigned int xp;
    sfSprite *sprite;
} player_t;

typedef struct parameters_s {
    sfRenderWindow* window;
    sfEvent event;
    sfSprite *background;
    sfClock *clock;
    sfMusic *music;
    char **map_array;
    player_t *player;
} parameters_t;

#endif
