/*
** EPITECH PROJECT, 2023
** my_strcat temp
** File description:
** bhkto-kgrthl-oh-toktjhikuoh
*/

#include "my.h"
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

char *my_strcat(char const *str, char const *to_add)
{
    size_t dest_size = strlen(str) + strlen(to_add);
    char *dest = malloc(sizeof(char) * (dest_size + 1));
    size_t i_dest = 0;
    size_t i_str = 0;

    if (strlen(str) == 0 || strlen(to_add) == 0) {
        return NULL;
    }
    while (i_dest < strlen(str)) {
        dest[i_dest] = str[i_dest];
        i_dest++;
    }
    while (i_dest < dest_size) {
        dest[i_dest] = to_add[i_str];
        i_dest++;
        i_str++;
    }
    dest[i_dest] = '\0';
    return dest;
}
