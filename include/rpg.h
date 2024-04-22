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

//-->main
int my_rpg(int, char **);

//---->> initialisation
void init_args(parameters_t *param);

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

//----> optimisation

#endif
