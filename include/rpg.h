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
    #define MAP_SPRITE_PATH "assets/maps/map1.png"
    #define MAP_ARRAY_PATH "tests/maps/map1.txt"
    #define PLAYER_CHAR 'P'
    #define OBSTACLE '#'
    #define EMPTY ' '
    #define MAP_WIDTH 60
    #define MAP_HEIGHT 33

// sprites
    #define PLAYER_SPRITE_PATH "assets/player/plane.png"
    #define MENU_BACKGROUND_PATH "assets/menu/menu_background.jpeg"
    #define PLAY_BUTTON_PATH "assets/menu/buttons/play.png"

// errors defines
    #define OPEN_ERROR -1
    #define ERROR 84
    #define SYS_ERROR -1

//-->main
int my_rpg(int, char **);

//---->> initialisation
int init_args(parameters_t *param);

char **get_map(char const *filepath);

//---> events
int window_events(parameters_t *param);
int mouse_events(parameters_t *param, int component);

//-->time
//int wait_time(sfClock *clock, float time_sleep);

//----> clean
void clean(parameters_t *param);
void free_entity(entity_t *entity);

//----> display
void display_sprites(parameters_t *param, int component);

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

// --> menu
bool start_menu(parameters_t *param);

// --> UI
int hovered(parameters_t *param, system_t *system, entity_t *entity);
void add_click_hover(entity_t *entity, int (*clicked)(parameters_t *,
    system_t *, entity_t *entity), int (*hovered)(parameters_t *, system_t *,
        entity_t *entity));
void reset_sprite(entity_t *entity);


#endif
