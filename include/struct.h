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
    MENU = 1 << 7,
    CLICKABLE = 1 << 8,
    SETTINGS = 1 << 9,
    IN_GAME_MENU = 1 << 10,
    ON_MAP = 1 << 11,
    LOADING = 1 << 12,
    HEART = 1 << 13,
    FULL_LIFE = 1 << 14,
    LOW_LIFE = 1 << 15,
    XP = 1 << 16,
    TEXT = 1 << 17,
    ITEM = 1 << 18,
    TUTORIAL = 1 << 18,
    IMAGE = 1 << 19,
    __END__ = 1 << 20,
} component_t;

typedef struct entity_s {
    int id;
    sfSprite *sprite;
    sfRectangleShape *rect;
    char *name;
    int (*clicked)(parameters_t *param, entity_t *entity, bool clicked);
    int (*hovered)(parameters_t *param, entity_t *entity, bool hovered);
    sfVector2f scale;
    sfVector2f pos;
    int attack;
    int health;
    sfTime entity_time;
    sfText *text;
} entity_t;

typedef struct sokospot_s {
    char type;
} sokospot_t;

typedef struct e_list_s {
    entity_t *entity;
    struct e_list_s *next;
} e_list_t;

typedef struct system_s {
    e_list_t *e_list;
    e_list_t *component[__END__];
} system_t;

typedef struct sounds_effect_s {
    sfSound *player_attack;
    sfSound *player_damage;
    sfSound *enemy_attack;
    sfSound *walk_1;
    sfSound *walk_2;
    sfSound *loading;
} sounds_effect_t;

typedef struct parameters_s {
    sfRenderWindow* window;
    sfView *view;
    sfEvent event;
    sfMusic *music;
    float sound_volume;
    sokospot_t ***map_array;
    system_t *sys;
    int game_state;
    sfClock *clock;
    sounds_effect_t *sounds_effect;
} parameters_t;

#endif
