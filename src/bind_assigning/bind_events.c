/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-nicolas.nunney
** File description:
** bind_events.c
*/

#include <string.h>
#include "rpg.h"
#include "associative.h"
#include "struct.h"

static void set_bind_2(entity_t *entity, bind_t *binds, sfKeyCode key)
{
    if (strcmp(entity->name, "slot_1") == 0)
        binds->pause = key;
    if (strcmp(entity->name, "slot_2") == 0)
        binds->pause = key;
    if (strcmp(entity->name, "slot_3") == 0)
        binds->pause = key;
    if (strcmp(entity->name, "slot_4") == 0)
        binds->pause = key;
}

static void set_bind(entity_t *entity, bind_t *binds, sfKeyCode key)
{
    if (!entity->name)
        return;
    if (strcmp(entity->name, "up") == 0)
        binds->up = key;
    if (strcmp(entity->name, "down") == 0)
        binds->down = key;
    if (strcmp(entity->name, "left") == 0)
        binds->left = key;
    if (strcmp(entity->name, "right") == 0)
        binds->right = key;
    if (strcmp(entity->name, "pick") == 0)
        binds->pick = key;
    if (strcmp(entity->name, "grab") == 0)
        binds->grab = key;
    if (strcmp(entity->name, "pause") == 0)
        binds->pause = key;
    set_bind_2(entity, binds, key);
}

int set_user_bind(parameters_t *param, entity_t *entity, bool state)
{
    sfVector2u window_size = sfRenderWindow_getSize(param->window);
    entity_t *message = create_entity(param->sys, SETTINGS);

    printf("in\n");
    message->text = sfText_create();
    sfText_setString(message->text, "press a key");
    sfText_setPosition(message->text,
        (sfVector2f){window_size.x / 2, window_size.y / 2});
    sfText_setColor(message->text, sfWhite);
    display_entities(param, SETTINGS);
    while (sfRenderWindow_pollEvent(param->window, &param->event)) {
        if (param->event.type == sfEvtClosed) {
            sfRenderWindow_close(param->window);
        }
        if (param->event.type == sfEvtKeyPressed) {
            set_bind(entity, param->binds, param->event.key.code);
        }
    }
    sfText_destroy(message->text);
    message->text = NULL;
    return SUCCESS;
}