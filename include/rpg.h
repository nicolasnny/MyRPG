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
    #define TIME_BEFORE_MOVE 30
    #define PLAYER_ATTACK_RANGE 60
    #define ENEMY_ATTACK_RANGE 30
    #define PLAYER_SPEED 4
    #define MOBS_SPEED 1
    #define GRAB_RANGE 30
    #define AGRO_DIST 150
    #define LOAD_MC_NAME "mc"
    #define LOAD_TIME_MOVE 30
    #define LOAD_RIGHT_MVT 10
    #define DEFAULT_SCALE 1.0
    #define DEFAULT_ENTITY_ATTACK 1
    #define DEFAULT_ENTITY_HEALTH 3
    #define DEFAULT_FONT "assets/fonts/aberus.ttf"

// map
    #define MAP_NAME "Royaume_de_Selestat"
    #define MAP_ARRAY_PATH "tests/maps/map1.txt"
    #define OBSTACLE '#'
    #define EMPTY ' '
    #define ENEMY 'E'
    #define MAP_WIDTH 360
    #define MAP_HEIGHT 200

// view
    #define DEFAULT_VIEW_SIZE_X 500
    #define DEFAULT_VIEW_SIZE_Y 288

// inventory
    #define INVENTORY_SPRITE "src/sprites/InventorySlots.png"
    #define SLOT_TOP 5
    #define SLOT1_WIDTH 33
    #define SLOT_WIDTH 17
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
    #define LOADING_SOUND "assets/sounds/loading.ogg"
    #define ENEMY_ATTACK_SOUND "assets/sounds/enemy_attack.flac"
    #define PLAYER_ATTACK_SOUND "assets/sounds/player_attack.flac"
    #define PLAYER_DAMMAGE_SOUND "assets/sounds/damage.flac"
    #define ENEMY_DAMAGE_SOUND "assets/sounds/enemy_damage.flac"
    #define PLAYER_WALK_1 "assets/sounds/walk_1.flac"
    #define PLAYER_WALK_2 "assets/sounds/walk_2.flac"
    #define BUMP_SOUND "assets/sounds/bump.flac"
    #define WALK_SOUND_RFRESH 200
    #define BUMP_SOUND_RFRESH 500
    #define DEFAULT_VOLUME 1.0
    #define MAX_VOLUME 100.0
    #define MID_VOLUME 50.0
    #define EFFECTS_VOLUME 20.0
    #define LOW_VOLUME 5.0
    #define MIN_VOLUME 0.0

// Player
    #define PLAYER_WALK_START 95
    #define PLAYER_IDLE_START 17
    #define PLAYER_ATTACK_START 135
    #define PLAYER_IDLE_DIFF PLAYER_HEIGHT + 11
    #define PLAYER_DAMMAGE_START 175
    #define PLAYER_WIDTH 32
    #define PLAYER_WIDTH_ATTACK 35
    #define PLAYER_HEIGHT 27
    #define REFRESH_SPEED_WALK 70
    #define REFRESH_SPEED_IDLE 900
    #define REFRESH_SPEED_DAMAGE 900
    #define MAX_WALK_TEXTURE 140
    #define MAX_IDLE_TEXTURE 70

// Enemy
    #define ENEMY_WALK_START 60
    #define ENEMY_ATTACK_START 105
    #define ENEMY_DAMMAGE_START 150
    #define ENEMY_WIDTH 40
    #define ENEMY_WIDTH_ATTACK 45
    #define ENEMY_HEIGHT 35
    #define ENEMY_MAX_WALK_TEXTURE 300
    #define ENEMY_MAX_DAMMAGE_TEXTURE 370
    #define ENEMY_MAX_IDLE_TEXTURE 70
    #define ENEMY_REFRESH_SPEED_WALK 150
    #define ENEMY_MAX_ATTACK_TEXTURE 700

// Quest
    #define DIST_TO_QUEST 40.0
    #define DIST_WITH_TRIGGER 20.0
    #define QUEST_HEIGHT_POURCENTAGE 0.8
    #define QUEST_WIDTH_PERCENTAGE 1.0
    #define RESET_BUTTON_X_OFFSET 80

// LIFE
    #define HEART_WIDTH 900
    #define HEART_LEFT_POURCENTAGE 0.45
    #define LOSE_LIFE_COOLDOWN 1000
    #define HEART_HEIGHT_POURCENTAGE 0.65

// xp
    #define XP_WIDTH 0.17
    #define XP_HEIGHT 0.93
    #define XP_RECT_HEIGHT 30
    #define XP_MAX_RECT_HEIGHT 180
    #define TXT_HEIGHT_GAP 2.5
    #define TXT_WIDTH_GAP 0.15
    #define DEFAULT_LVL_FONT_SIZE 15

//-->main
int my_rpg(int, char **);

//---->> initialisation
int init_args(parameters_t *param);
int init_inventory(parameters_t *param, entity_t *entity, bool state);
sfMusic *init_sound(char *path);
void launch_music(parameters_t *param);
sokospot_t ***get_map(char const *filepath);
sounds_effect_t *init_sounds_effect(void);

//---> events
int window_events(parameters_t *param, int component);
void make_life(parameters_t *param);
int mouse_events(parameters_t *param, int component, e_list_t *compo_list);

//----> clean
void clean(parameters_t *param);
void free_entity(entity_t *entity);

//----> display
void display_entities(parameters_t *param, int component);

//----> error handling
int err_handling(int ac, char **av);

// --> moves
void move_player
(parameters_t *param, sfIntRect *texture_pos,
    sfIntRect *idle_pos, sfVector2f *scale);
void move_mobs(parameters_t *param, sokospot_t ***map);
void set_player_first_pos(sfView *view, sokospot_t ***map);
void swap_struct(sokospot_t **current, sokospot_t **target);
void set_player_new_pos(parameters_t *param, sfVector2f move);
sfVector2f get_p_move_event(sfVector2f *map_size, sfSprite *player);
bool get_sprite_coords_on_sokomap(sfVector2f *map_size, sfSprite *s,
    int *line, int *col);
sfVector2f get_map_size(system_t *sys);
sfSprite *get_player(system_t *sys);
sokospot_t *get_entity_spot(sokospot_t ***map, entity_t *e);
void flip_sprite(sfVector2f move, sfSprite *player, sfVector2f *scale);

// Animation
void animate_player_walk
(parameters_t *param, sfIntRect *texture_pos, sfSprite *player);
void animate_idle(sfIntRect *idle_pos, sfSprite *player);
void animate_attack
(parameters_t *param, sfIntRect *texture_pos, sfSprite *player);
void anime_enemy_walk(parameters_t *param, entity_t *enemy);
void anime_enemy_fight(parameters_t *param, entity_t *enemy);
//void anime_enemy_die(parameters_t *param, entity_t *enemy);

//----> utilities
// char **my_pimp_str_to_wa(char *str, char *delim);
char *get_file_content(char const *filename);
int read_open(char const *filename);
int open_append(char const *filename);
int get_file_size(char const *filename);
// unsigned int my_strstrlen(char **array);
void free_str_array(char **map);
sfVector2f get_center(sfSprite *s);
bool check_monsters(parameters_t *param, entity_t *player);

// ECS
// --> entity
bool set_entity(entity_t *entity, system_t *system, int component);
entity_t *create_entity(parameters_t *param, int compo);
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
void set_text_scale(parameters_t *param, entity_t *entity, char *value);

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
int check_player_collisions(parameters_t *param);

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
void item_management(parameters_t *param);

// --> fight
bool enemy_in_range(entity_t *player, entity_t *enemy, unsigned int range);
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

// --> loading screen
int loading_screen_loop(parameters_t *param);

// --> text
void set_text(parameters_t *param, entity_t *entity, char *value);

// --> quests
void check_quest(parameters_t *param);
int reset_quest(parameters_t *param, entity_t *entity, bool state);
bool fisherman(parameters_t *param);
int launch_fisherman(parameters_t *param, entity_t *entity, bool state);
void set_quest_pos(parameters_t *param);

// --> life
void refresh_heart_position(system_t *sys);
void move_heart_rect(sfSprite *s);
void remove_life(system_t *sys);
bool is_player_alive(system_t *sys);
int add_life(parameters_t *param, entity_t *e, bool state);

// --> tutorial
int tutorial(parameters_t *param, entity_t *entity, bool state);
int prev_image(parameters_t *param, entity_t *entity, bool state);
int next_image(parameters_t *param, entity_t *entity, bool state);

// --> lvl
void refresh_lvl_pos(system_t *sys);
void move_lvl_rect(parameters_t *param);

// --> health and attack
void set_health(parameters_t *param, entity_t *entity, char *value);
void set_attack(parameters_t *param, entity_t *entity, char *value);

#endif
