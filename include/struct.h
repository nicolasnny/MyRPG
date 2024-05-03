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

typedef struct parameters_s parameters_t;
typedef struct system_s system_t;

typedef enum game_state_s {
    PLAY = 1,
    QUIT = 0,
    SELECT = -1,
} game_state_t;

typedef enum component_s {
    PLAYER = 1 << 0,
    NPC = 1 << 1,
    VISIBLE = 1 << 2,
    CLICKABLE = 1 << 3,
    MENU = 1 << 4,
    __END__ = 1 << 5,
} component_t;

typedef struct entity_s {
    int id;
    sfSprite *sprite;
    int (*clicked)(parameters_t *param, system_t *system,
        struct entity_s *entity);
    int (*hovered)(parameters_t *param, system_t *system,
        struct entity_s *entity);
} entity_t;

typedef struct e_list_s {
    entity_t *entity;
    struct e_list_s *next;
} e_list_t;

typedef struct system_s {
    e_list_t *e_list;
    e_list_t *component[__END__];
} system_t;

typedef struct parameters_s {
    sfRenderWindow* window;
    sfEvent event;
    sfSprite *background;
    sfClock *clock;
    sfMusic *music;
    char **map_array;
    system_t *sys;
} parameters_t;

#endif
