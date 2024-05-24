/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** lvl
*/

#include <string.h>
#include "my.h"
#include "rpg.h"

static void set_text_lvl_pos(system_t *sys)
{
    e_list_t *xp_bar = get_entities(sys, BAR | XP | VISIBLE);
    e_list_t *txt_list = get_entities(sys, TEXT | XP | VISIBLE);
    sfVector2f pos = {0};

    if (sys == NULL || xp_bar == NULL || txt_list)
        return;
    pos = sfSprite_getPosition(xp_bar->entity->sprite);
    pos.y -= sfText_getGlobalBounds(txt_list->entity->text).height
    + LVL_GAP_WITH_BAR;
    pos.x += sfSprite_getGlobalBounds(xp_bar->entity->sprite).width -
    sfText_getGlobalBounds(txt_list->entity->text).width;
}

static void set_lvl_pos(system_t *sys)
{
    sfVector2f pos = {0};
    e_list_t *xp = get_entities(sys, XP | BAR | VISIBLE);
    e_list_t *player = get_entities(sys, PLAYER | VISIBLE);
    sfVector2f player_center_pos = {0};

    if (xp == NULL || player == NULL)
        return;
    player_center_pos = get_center(player->entity->sprite);
    pos.x = player_center_pos.x - DEFAULT_VIEW_SIZE_X / 2 + DEFAULT_VIEW_SIZE_X
    * XP_WIDTH;
    pos.y = player_center_pos.y - DEFAULT_VIEW_SIZE_Y / 2 + DEFAULT_VIEW_SIZE_Y
    * XP_HEIGHT;
    sfSprite_setPosition(xp->entity->sprite, pos);
    clean_list(xp);
    clean_list(player);
}

void refresh_lvl_pos(system_t *sys)
{
    set_lvl_pos(sys);
    set_text_lvl_pos(sys);
}

static void updtate_text(system_t *sys, int lvl)
{
    e_list_t *l = get_entities(sys, TEXT | XP | VISIBLE);
    char *txt = "Level ";
    char *lvl_txt = NULL;

    if (l == NULL)
        return;
    lvl_txt = my_nb_to_str(lvl);
    if (lvl == NULL) {
        clean_list(l);
        return;
    }
    txt = strcat(txt, lvl_txt);
    sfText_setString(l->entity->text, txt);
    clean_list(l);
}

void move_lvl_rect(system_t *sys)
{
    e_list_t *xp = get_entities(sys, XP);
    sfIntRect rect = {0};
    static int lvl = 0;

    if (xp == NULL || xp->entity->sprite == NULL)
        return;
    lvl += 1;
    rect = sfSprite_getTextureRect(xp->entity->sprite);
    rect.top -= rect.height;
    if (rect.top < 0)
        rect.top = XP_MAX_RECT_HEIGHT - rect.height;
    sfSprite_setTextureRect(xp->entity->sprite, rect);
    clean_list(xp);
}
