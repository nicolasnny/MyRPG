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

// map
    #define MAP_SPRITE_PATH "src/sprites/maps/map1.png"
    #define MAP_ARRAY_PATH "tests/maps/map1.txt"
    #define PLAYER 'P'
    #define OBSTACLE '#'
    #define EMPTY ' '
    #define MAP_WIDTH 60
    #define MAP_HEIGHT 33

// sprites
    #define PLAYER_SPRITE_PATH "src/sprites/plane.png"

// errors defines
    #define OPEN_ERROR -1
    #define ERROR 84
    #define SYS_ERROR -1

//-->main
int my_rpg(int, char **);

//---->> initialisation
int init_args(parameters_t *param);
int init_player(parameters_t *param);

char **get_map(char const *filepath);

//---> events
int analyse_events(parameters_t *param);

//-->time
//int wait_time(sfClock *clock, float time_sleep);

//----> clean
void clean(parameters_t *param);

//----> display
void display_sprites(parameters_t *param);

//----> error handling
int err_handling(int ac, char **av);

// --> moves
void move_player(parameters_t *param);
void set_player_new_pos(parameters_t *param, char **map);

//----> utilities
char **my_pimp_str_to_wa(char *str, char *delim);
char *get_file_content(char const *filename);
int read_open(char const *filename);
int open_append(char const *filename);
int get_file_size(char const *filename);

//----> ECS
bool set_entity(entity_t *entity, system_t *system, int component);


#endif
