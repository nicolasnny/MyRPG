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

typedef enum component_s {
    PLAYER = 1 << 0,
    NPC = 1 << 1,
    VISIBLE = 1 << 2,
    __END__ = 1 << 4,
} component_t;

typedef struct entity_s {
    sfSprite *sprite;
} entity_t;

typedef struct e_list_s {
    entity_t *entity;
    struct e_list_s *next;
} e_list_t;

typedef struct system_s {
    e_list_t *e_list;
    component_t component[__END__];
} system_t;

typedef struct parameters_s {
    sfRenderWindow* window;
    sfEvent event;
    sfSprite *background;
    sfClock *clock;
    sfMusic *music;
    char **map_array;
    system_t *system;
} parameters_t;

#endif
