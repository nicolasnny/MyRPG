/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-nicolas.nunney
** File description:
** rpg.h
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
    #define MAP_SPRITE_PATH "assets/maps/map1.png"
    #define MAP_ARRAY_PATH "tests/maps/map1.txt"
    #define PLAYER_CHAR 'P'
    #define OBSTACLE '#'
    #define EMPTY ' '
    #define ENEMY 'E'
    #define NPC_LIMIT 'L'
    #define MAP_WIDTH 60
    #define MAP_HEIGHT 33

// sprites
    #define PLAYER_SPRITE_PATH "assets/player/plane.png"
    #define MOB_SPRITE_PATH "assets/player/plane.png"
    #define NPC_SPRITE_PATH "assets/player/plane.png"
    #define MENU_BACKGROUND_PATH "assets/menu/menu_background.jpeg"
    #define PLAY_BUTTON_PATH "assets/menu/buttons/play.png"
    #define QUIT_BUTTON_PATH "assets/menu/buttons/quit.png"
    #define OPTION_BUTTON_PATH "assets/menu/buttons/options.png"

// errors defines
    #define OPEN_ERROR -1
    #define ERROR 84
    #define SYS_ERROR -1

// CONFIG
    #define CONFIG_DIR "config/"
    #define CONFIG_ELEMENT_NAME "[ENTITY]"

//-->main
int my_rpg(int, char **);

//---->> initialisation
int init_args(parameters_t *param);

sokospot_t ***get_map(char const *filepath, system_t *sys);

//---> events
int window_events(parameters_t *param);
void make_life(parameters_t *param);
int mouse_events(parameters_t *param, int component);

//-->time
//int wait_time(sfClock *clock, float time_sleep);

//----> clean
void clean(parameters_t *param);
void free_entity(entity_t *entity);

//----> display
void display_entities(parameters_t *param, int component);

//----> error handling
int err_handling(int ac, char **av);

// --> moves
void move_player(parameters_t *param);
void move_mobs(sokospot_t ***map);
void set_player_new_pos(sokospot_t ***map);
void swap_struct(sokospot_t **current, sokospot_t **target);

//----> utilities
// char **my_pimp_str_to_wa(char *str, char *delim);
char *get_file_content(char const *filename);
int read_open(char const *filename);
int open_append(char const *filename);
int get_file_size(char const *filename);
// unsigned int my_strstrlen(char **array);
void free_str_array(char **map);

// ECS
// --> entity
bool set_entity(entity_t *entity, system_t *system, int component);
entity_t *create_entity(system_t *sys, int component);
e_list_t *get_entities(system_t *sys, int component);
void set_scale(entity_t *e, char *value, sfIntRect *rect);
void set_pos(entity_t *e, char *value, sfIntRect *rect);
void set_hover(entity_t *e, char *value, sfIntRect *rect);
void set_click(entity_t *e, char *value, sfIntRect *rect);
void set_texture(entity_t *entity, char *value,
    sfIntRect *rect);

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

// --> game state
int set_to_play(parameters_t *param, entity_t *entity, bool clicked);
int set_to_quit(parameters_t *param, entity_t *entity, bool clicked);
int set_to_pause(parameters_t *param, entity_t *entity, bool clicked);

// --> menu
bool start_menu(parameters_t *param);

// --> UI
int hovered(parameters_t *param, entity_t *entity, bool hovered);

// --> config parser
char **get_config(void);
void create_from_conf(parameters_t *param);

// --> rectangleShape
void create_rectangle(entity_t *e, char *value, sfIntRect *rect);
void set_rectangle_texture(entity_t *e, char const *texture_path,
    sfIntRect *rect);

// --> Sprite
void create_sprite(entity_t *e, char *value, sfIntRect *rect);
void set_sprite_texture(entity_t *e, char const *texture_path,
    sfIntRect *rect);


#endif
