/*
** EPITECH PROJECT, 2023
** MY_RADAR
** File description:
** Functions for the my_radar project
*/

#ifndef RPG_H
    #define RPG_H
    #include "struct.h"
    #include <stdbool.h>

//---> constant values
    #define SUCCESS 0
    #define WIN_WIDTH 1920
    #define WIN_HEIGHT 1080
    #define WIN_PIX_NB 32
    #define FPS 64
    #define END_OF_MAP_LINE '|'
    #define NO_ARROW_KEY_PRESSED 0
    #define IN 1
    #define OUT -1
    #define NOT_FOUND -1
    #define TIME_BEFORE_MOBS_MOVE 3

// map
    #define MAP_SPRITE_PATH "src/sprites/maps/map1.png"
    #define MAP_ARRAY_PATH "tests/maps/map1.txt"
    #define PLAYER_CHAR 'P'
    #define OBSTACLE '#'
    #define EMPTY ' '
    #define ENEMY 'E'
    #define NPC_LIMIT 'L'
    #define MAP_WIDTH 60
    #define MAP_HEIGHT 33

// inventory
    #define INVENTORY_SPRITE "src/sprites/inventory.png"
    #define INVENTORY_HEIGHT 103
    #define INVENTORY_WIDTH 24

// sprites
    #define PLAYER_SPRITE_PATH "src/sprites/plane.png"
    #define MOB_SPRITE_PATH "src/sprites/plane.png"
    #define NPC_SPRITE_PATH "src/sprites/plane.png"

// errors defines
    #define OPEN_ERROR -1
    #define ERROR 84
    #define SYS_ERROR -1

//-->main
int my_rpg(int, char **);

//---->> initialisation
int init_args(parameters_t *param);
int init_inventory(parameters_t *param);

sokospot_t ***get_map(char const *filepath, system_t *sys);

//---> events
int analyse_events(parameters_t *param);
void make_life(parameters_t *param);

//-->time
//int wait_time(sfClock *clock, float time_sleep);

//----> clean
void clean(parameters_t *param);
void free_entity(entity_t *entity);

//----> display
void display_sprites(parameters_t *param);

//----> error handling
int err_handling(int ac, char **av);

// --> moves
void move_player(parameters_t *param);
void move_mobs(sokospot_t ***map);
void set_player_new_pos(sokospot_t ***map);
void swap_struct(sokospot_t **current, sokospot_t **target);

//----> utilities
char **my_pimp_str_to_wa(char *str, char *delim);
char *get_file_content(char const *filename);
int read_open(char const *filename);
int open_append(char const *filename);
int get_file_size(char const *filename);
unsigned int my_strstrlen(char **array);
void free_str_array(char **map);

// ECS
// --> entity
bool set_entity(entity_t *entity, system_t *system, int component);
entity_t *create_entity(system_t *sys, char const *texture_path,
    sfIntRect *rect, int component);
e_list_t *get_entities(system_t *sys, int component);

// --> system
system_t *create_system(void);

// --> linked_list
bool push_to_list(e_list_t **head, entity_t *e);
bool remove_from_list(e_list_t **list, entity_t *e);
bool entity_in_list(e_list_t *list, entity_t *e);
bool clean_list(e_list_t *list);
void display_entity_id(e_list_t *list);
void reverse_list(e_list_t **head);

// --> collisions
int check_player_collisions(system_t *sys);

// --> random
int random_nb(int a, int b);

#endif
