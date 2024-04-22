/*
** EPITECH PROJECT, 2023
** MY_RADAR
** File description:
** Functions for the my_radar project
*/

#ifndef RPG_H
    #define RPG_H
    #include "struct.h"

//---> constant values
    #define SUCCESS 0
    #define ERROR 84
    #define WIN_WIDTH 1920
    #define WIN_HEIGHT 1080
    #define WIN_PIX_NB 32
    #define FPS 64
    #define END_OF_MAP_LINE '|'
    #define NO_ARROW_KEY_PRESSED 0

// map
    #define MAP_SPRITE_PATH "src/sprites/maps/map1.png"
    #define MAP_ARRAY_PATH "tests/maps/map1.txt"
    #define PLAYER 'P'
    #define OBSTACLE '#'
    #define EMPTY ' '

//-->main
int my_rpg(int, char **);

//---->> initialisation
void init_args(parameters_t *param);

//---> events
int analyse_events(parameters_t *param);
int get_p_move_event(void);

//-->time
//int wait_time(sfClock *clock, float time_sleep);

//----> clean
void clean(parameters_t *param);

//----> display
void display_sprites(parameters_t *param);

//----> error handling
int err_handling(int ac, char **av);

//----> moves
void move_player(parameters_t *param);

#endif
