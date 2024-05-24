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

    if (sys == NULL || xp_bar == NULL || txt_list == NULL ||
        txt_list->entity->text == NULL)
        return;
    sfText_setCharacterSize(txt_list->entity->text, DEFAULT_LVL_FONT_SIZE);
    pos = sfSprite_getPosition(xp_bar->entity->sprite);
    pos.y -= sfText_getGlobalBounds(txt_list->entity->text).height *
    TXT_HEIGHT_GAP;
    pos.x += sfSprite_getGlobalBounds(xp_bar->entity->sprite).width *
    TXT_WIDTH_GAP;
    sfText_setPosition(txt_list->entity->text, pos);
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
    if (lvl_txt == NULL) {
        clean_list(l);
        return;
    }
    txt = my_strcat(txt, lvl_txt);
    sfText_setString(l->entity->text, txt);
    clean_list(l);
}

static void update_lvl(entity_t *player, int *lvl)
{
    player->attack += 1;
    *lvl += 1;
}

bool move_lvl_rect(parameters_t *param)
{
    e_list_t *xp = get_entities(param->sys, XP | BAR | VISIBLE);
    e_list_t *player = get_entities(param->sys, PLAYER | VISIBLE);
    sfIntRect rect = {0};
    static int lvl = 1;
    bool ret = false;

    if (xp == NULL || xp->entity->sprite == NULL || player == NULL)
        return true;
    rect = sfSprite_getTextureRect(xp->entity->sprite);
    rect.top -= rect.height;
    if (rect.top < 0) {
        rect.top = XP_MAX_RECT_HEIGHT - rect.height;
        update_lvl(player->entity, &lvl);
        add_life(param, NULL, false);
        updtate_text(param->sys, lvl);
        ret = true;
    }
    sfSprite_setTextureRect(xp->entity->sprite, rect);
    clean_list(xp);
    return ret;
}

int add_one_lvl(parameters_t *param, entity_t *e, bool state)
{
    while (!move_lvl_rect(param));
    (void)e;
    (void)state;
    return SUCCESS;
}
