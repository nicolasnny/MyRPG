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

typedef enum game_state_s {
    PLAY,
    QUIT,
    PAUSE
} game_state_t;

typedef enum component_s {
    PLAYER = 1 << 0,
    NPC = 1 << 1,
    VISIBLE = 1 << 2,
    MENU = 1 << 3,
    MOB = 1 << 4,
    CLICKABLE = 1 << 5,
    SETTINGS = 1 << 6,
    __END__ = 1 << 7,
} component_t;

typedef struct entity_s {
    int id;
    sfSprite *sprite;
    sfRectangleShape *rect;
    int (*clicked)(parameters_t *param, system_t *system,
        struct entity_s *entity, bool clicked);
    int (*hovered)(parameters_t *param, system_t *system,
        struct entity_s *entity, bool hovered);
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

typedef struct function_s {
    char *func_name;
    int (*function)(parameters_t *param, system_t *system,
        struct entity_s *entity, bool hovered);
} function_t;

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
    sokospot_t ***map_array;
    system_t *sys;
    int game_state;
} parameters_t;

#endif
