/*
** EPITECH PROJECT, 2024
** my_str_dup_ban_char
** File description:
** strdup_ban_char
*/

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

bool char_is_in(char *str, char c, int inhib)
{
    if (inhib == -1)
        return false;
    for (unsigned int i = 0; str[i] != '\0'; i++) {
        if (c == str[i])
            return true;
    }
    return false;
}

size_t my_strlen_ban_char(char *str, char *banned_chars)
{
    size_t len = 0;
    int inhib = 1;

    if (!str | !banned_chars) {
        return 0;
    }
    for (unsigned int i = 0; str[i]; i++) {
        if (str[i] == '\"') {
            inhib *= -1;
        }
        if (!char_is_in(banned_chars, str[i], inhib) && str[i] != '\"') {
            len++;
        }
    }
    return len;
}

char *strdup_banned_chars(char *str, char *ban)
{
    char *new_str = malloc(sizeof(char) * my_strlen_ban_char(str, ban) + 1);
    unsigned int index = 0;
    int inhib = 1;

    if (!new_str || !str || !ban) {
        return NULL;
    }
    for (unsigned int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\"')
            inhib *= -1;
        if (!char_is_in(ban, str[i], inhib) && str[i] != '\"') {
            new_str[index] = str[i];
            index++;
        }
    }
    new_str[index] = '\0';
    return new_str;
}
