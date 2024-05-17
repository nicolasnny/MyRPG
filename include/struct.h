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
    #include <stdbool.h>

typedef struct parameters_s parameters_t;
typedef struct system_s system_t;
typedef struct entity_s entity_t;

typedef enum game_state_s {
    PLAY,
    QUIT,
    PAUSE
} game_state_t;

typedef enum component_s {
    PLAYER = 1 << 0,
    NPC = 1 << 1,
    VISIBLE = 1 << 2,
    MOB = 1 << 3,
    INVENTORY = 1 << 4,
    SELECTED = 1 << 5,
    BAR = 1 << 6,
    __END__ = 1 << 7,
} component_t;

typedef struct entity_s {
    int id;
    sfSprite *sprite;
    sfRectangleShape *rect;
    int (*clicked)(parameters_t *param, entity_t *entity, bool clicked);
    int (*hovered)(parameters_t *param, entity_t *entity, bool hovered);
    sfText *text;
} entity_t;

typedef struct sokospot_s {
    entity_t *entity;
    char type;
    bool moved_in_frame;
} sokospot_t;

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
    sfView *view;
    sfEvent event;
    sfSprite *background;
    sfClock *clock;
    sfMusic *music;
    sokospot_t ***map_array;
    system_t *sys;
    int game_state;
} parameters_t;

#endif
