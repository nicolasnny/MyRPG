/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** Functions related to the inventory
*/

#include <SFML/Graphics.h>
#include "rpg.h"
#include "struct.h"

/*static unsigned int count_lines(char const *msg)
{
    unsigned int line_nb = 0;

    if (msg == NULL) {
        return 0;
    }
    for (unsigned int i = 0; msg[i]; i++) {
        if (msg[i] == '\n') {
            line_nb++;
        }
    }
    return line_nb;
}*/

static sfFont *create_font(char const *font_path)
{
    sfFont *font = NULL;

    if (font_path == NULL) {
        return NULL;
    }
    font = sfFont_createFromFile(font_path);
    return font;
}

static void set_msg_pos(sfSprite *inventory_sprite, sfText *txt)
{
    sfFloatRect s_bounds = sfSprite_getGlobalBounds(inventory_sprite);
    sfVector2f t_pos = {0};

    t_pos.x = s_bounds.left +
        (DESCRIPTION_BOX_START / DESCRIPTION_BOX_END) * s_bounds.width / 2;
    t_pos.y = s_bounds.top + s_bounds.height / 2;
    sfText_setPosition(txt, t_pos);
}

sfText *create_inventory_description_text(sfSprite *inventory_sprite, char const *msg)
{
    sfText *txt = sfText_create();
    sfFont *font = create_font(FONT_PATH);

    if (txt == NULL) {
        return NULL;
    }
    if (msg == NULL) {
        sfText_destroy(txt);
        return create_inventory_description_text(inventory_sprite, "No item selected");
    }
    set_msg_pos(inventory_sprite, txt);
    sfText_setString(txt, msg);
    sfText_setCharacterSize(txt, DESCRIPTION_FONT_SIZE);
    if (font != NULL) {
        sfText_setFont(txt, font);
    }
    return txt;
}
