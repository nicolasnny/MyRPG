/*
** EPITECH PROJECT, 2024
** MY_RPG
** File description:
** Init the player and npcs
*/

#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics.h>
#include "rpg.h"
#include "struct.h"

static int set_texture_sprite(player_t *player)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = NULL;

    if (sprite == NULL) {
        dprintf(2, "Error: unable to create new sprite for player\n");
        return ERROR;
    }
    player->sprite = sprite;
    texture = sfTexture_createFromFile(PLAYER_SPRITE_PATH, NULL);
    if (texture == NULL) {
        sfSprite_destroy(sprite);
        dprintf(2, "Error: unable to load \"%s\" as a texture\n",
        PLAYER_SPRITE_PATH);
        return ERROR;
    }
    sfSprite_setTexture(player->sprite, texture, sfFalse);
    return SUCCESS;
}

int init_player(void)
{
    player_t *player = malloc(sizeof(player_t));

    if (player == NULL) {
        perror("player struct malloc failed");
        return ERROR;
    }
    player->lvl = 0;
    player->xp = 0;
    if (set_texture_sprite(player) == ERROR) {
        return ERROR;
    }
    return SUCCESS;
}
