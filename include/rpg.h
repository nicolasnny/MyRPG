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
    #define FONT_PATH "src/sprites/game_font.ttf"
    #define PLAYER_ATTACK_RANGE 50
    #define PLAYER_SPEED 2.2
    #define DEFAULT_NAME "Mob"
    #define GRAB_RANGE 30

// map
    #define MAP_NAME "Royaume_de_Selestat"
    #define MAP_SPRITE_PATH "assets/maps/map2.png"
    #define MAP_ARRAY_PATH "tests/maps/map1.txt"
    #define PLAYER_CHAR 'P'
    #define OBSTACLE '#'
    #define EMPTY ' '
    #define ENEMY 'E'
    #define NPC_LIMIT 'L'
    #define NPC_CHAR 'N'
    #define MAP_WIDTH 360
    #define MAP_HEIGHT 200
    #define TMP_HEIGHT 60
    #define TMP_WIDTH 33

// view
    #define DEFAULT_VIEW_SIZE_X 500
    #define DEFAULT_VIEW_SIZE_Y 288

// inventory
    #define INVENTORY_SPRITE "src/sprites/InventorySlots.png"
    #define SLOT_TOP 5
    #define SLOT1_WIDTH 33
    #define SLOT_WIDTH 17
    #define DESCRIPTION_BOX_START 32
    #define DESCRIPTION_BOX_END 99
    #define DESCRIPTION_FONT_SIZE 14
    #define INVENTORY_SCALE 1.5
    #define INVENTORY_HEIGHT_POURCENTAGE 0.8
    #define INVENTORY_CAPACITY 4
    #define SLOT_ERROR_UP_MARGIN 1.1
    #define SLOT_ERROR_DOWN_MARGIN 0.9

// errors defines
    #define OPEN_ERROR -1
    #define ERROR 84
    #define NEG_ERROR -1
    #define SYS_ERROR -1

// in game menu
    #define MENU_OFFSET 100
    #define MENU_UNZOOM 1.5
    #define MENU_ZOOM 0.66666666666667

// errors defines
    #define OPEN_ERROR -1
    #define ERROR 84
    #define NEG_ERROR -1
    #define SYS_ERROR -1

// CONFIG
    #define CONFIG_DIR "config/"
    #define CONFIG_ELEMENT_NAME "[ENTITY]"

// Sounds
    #define MUSIC_PATH "assets/sounds/music.wav"
    #define AMBIANT_SOUND_PATH "assets/sounds/nature.mp3"
    #define DEFAULT_VOLUME 100.0
    #define MAX_VOLUME 100.0
    #define MIN_VOLUME 0.0

// Player
    #define PLAYER_WALK_START 90
    #define PLAYER_IDLE_START 10
    #define PLAYER_WIDTH 40
    #define PLAYER_HEIGHT 30
    #define REFRESH_SPEED_WALK 70
    #define REFRESH_SPEED_IDLE 900
    #define MAX_WALK_TEXTURE 140
    #define MAX_IDLE_TEXTURE 70


//-->main
int my_rpg(int, char **);

//---->> initialisation
int init_args(parameters_t *param);
int init_inventory(parameters_t *param, entity_t *entity, bool state);
sfSound *init_sound(char *path);

sokospot_t ***get_map(char const *filepath, system_t *sys);

//---> events
int window_events(parameters_t *param, int component);
void make_life(parameters_t *param);
int mouse_events(parameters_t *param, int component);

//-->time
//int wait_time(sfClock *clock, float time_sleep);

//----> clean
void clean(parameters_t *param);
void free_entity(entity_t *entity);

//----> display
void display_entities(parameters_t *param, int component);
void display_entities(parameters_t *param, int component);

//----> error handling
int err_handling(int ac, char **av);

// --> moves
void move_player(parameters_t *param, sfSprite *player, sfVector2f map_size);
void move_mobs(sokospot_t ***map);
void set_player_first_pos(sfView *view, sokospot_t ***map);
void swap_struct(sokospot_t **current, sokospot_t **target);
void set_player_new_pos(parameters_t *param, sfVector2f move);
sokospot_t *get_player_spot(sokospot_t ***);
sfVector2f get_p_move_event(sfVector2f *map_size, sfSprite *player);
bool get_sprite_coords_on_sokomap(sfVector2f *map_size, sfSprite *s,
    int *line, int *col);
sfVector2f get_map_size(system_t *sys);
sfSprite *get_player(system_t *sys);
void flip_sprite
(sfVector2f *move_save, sfVector2f move, sfSprite *player, sfVector2f *scale);
void animate_player_walk(sfIntRect *texture_pos, sfSprite *player);
void annimate_idle(sfIntRect *idle_pos, sfSprite *player);
sokospot_t *get_entity_spot(sokospot_t ***map, entity_t *e);

//----> utilities
// char **my_pimp_str_to_wa(char *str, char *delim);
// char **my_pimp_str_to_wa(char *str, char *delim);
char *get_file_content(char const *filename);
int read_open(char const *filename);
int open_append(char const *filename);
int get_file_size(char const *filename);
// unsigned int my_strstrlen(char **array);
// unsigned int my_strstrlen(char **array);
void free_str_array(char **map);
sfVector2f get_center(sfSprite *s);

// ECS
// --> entity
bool set_entity(entity_t *entity, system_t *system, int component);
entity_t *create_entity(system_t *sys, int component);
entity_t *create_entity(system_t *sys, int component);
e_list_t *get_entities(system_t *sys, int component);
void set_scale(parameters_t *param, entity_t *entity, char *value);
void set_pos(parameters_t *param, entity_t *entity, char *value);
void set_hover(parameters_t *param, entity_t *entity, char *value);
void set_click(parameters_t *param, entity_t *entity, char *value);
void set_texture(parameters_t *param, entity_t *entity, char *value);
bool unset_entity(system_t *sys, entity_t *e, int component);
void set_name(parameters_t *param, entity_t *entity, char *value);
bool remove_entity(system_t *sys, entity_t *e);
entity_t *get_entity_by_name(system_t *sys, char const *name);
bool remove_entity_from_map(sokospot_t ***map, entity_t *e);

// --> system
system_t *create_system(void);

// --> linked_list
bool push_to_list(e_list_t **head, entity_t *e);
bool remove_from_list(e_list_t **list, entity_t *e);
bool entity_in_list(e_list_t *list, entity_t *e);
bool clean_list(e_list_t *list);
void display_entity_id(e_list_t *list);
void reverse_list(e_list_t **head);
bool remove_entity_from_list(e_list_t **list, entity_t *e);
unsigned int get_list_size(e_list_t *list);

// --> collisions
int check_player_collisions(system_t *sys);

// --> random
int random_nb(int a, int b);

// --> game state
int set_to_play(parameters_t *param, entity_t *entity, bool clicked);
int set_to_quit(parameters_t *param, entity_t *entity, bool clicked);
int set_to_pause(parameters_t *param, entity_t *entity, bool clicked);

// --> menu
int start_menu(parameters_t *param, entity_t *entity, bool state);
int options_menu(parameters_t *param, entity_t *entity, bool state);
void in_game_menu(parameters_t *param);

// --> UI
int hovered(parameters_t *param, entity_t *entity, bool hovered);

// --> config parser
char **get_config(void);
void create_from_conf(parameters_t *param);
int *get_int_array(char *arg);
double *get_double_array(char *arg);
void run_on_start(parameters_t *param, entity_t *entity, char *value);

int *get_int_array(char *arg);
double *get_double_array(char *arg);
void run_on_start(parameters_t *param, entity_t *entity, char *value);


// --> rectangleShape
void create_rectangle(parameters_t *param, entity_t *entity, char *value);
void set_rectangle_texture(entity_t *e, char const *texture_path,
    sfIntRect *rect);

// --> Sprite
void create_sprite(parameters_t *param, entity_t *entity, char *value);
void set_sprite_texture(entity_t *e, char const *texture_path,
    sfIntRect *rect);

// --> inventory
bool add_element_to_inventory(system_t *sys, entity_t *e);
void set_inventory_items_pos(system_t *sys);
void set_inventory_pos(system_t *sys);
void refresh_inventory_pos(system_t *sys);
void change_selected_item(system_t *sys);
void get_item(parameters_t *param);
void drop_selected_item(system_t *sys);
void grab_drop_events(parameters_t *param);

// --> fight
bool ennemy_in_range(entity_t *player, entity_t *ennemy);
int kill_entity(parameters_t *param, entity_t *entity, bool state);
double get_distance_bewteen_pos(sfVector2f *pa, sfVector2f *pb);

// --> window size
int set_2560x1600(parameters_t *param, entity_t *entity, bool state);
int set_1920x1080(parameters_t *param, entity_t *entity, bool state);

// --> view
void reset_view(parameters_t *param);
void set_view_on_player(parameters_t *param);
sfVector2f get_view_pos(sfView *v);
sfView *create_view(void);
void destroy_view(parameters_t *param);

// --> volume
int reset_music_volume(parameters_t *param, entity_t *entity, bool state);
int set_music_volume_up(parameters_t *param, entity_t *entity, bool state);
int set_music_volume_down(parameters_t *param, entity_t *entity, bool state);
int reset_sound_volume(parameters_t *param, entity_t *entity, bool state);
int set_sound_volume_up(parameters_t *param, entity_t *entity, bool state);
int set_sound_volume_down(parameters_t *param, entity_t *entity, bool state);

#endif
