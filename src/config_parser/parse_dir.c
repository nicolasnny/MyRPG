/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-nicolas.nunney
** File description:
** parse_dir.c
*/

#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include "my.h"
#include "rpg.h"

static char *get_output(int fd, int size)
{
    char *buffer = malloc(sizeof(char) * size + 1);
    ssize_t len;

    for (int i = 0; i != size; i++) {
        buffer[i] = '\0';
    }
    len = read(fd, buffer, size);
    if (len == -1) {
        return NULL;
    }
    buffer[len] = '\0';
    return buffer;
}

static char *get_new_file(char *file_name)
{
    char *file_path = my_strcat(CONFIG_DIR, file_name);
    int fd = open(file_path, O_RDONLY);
    struct stat file = {0};

    if (fd == -1) {
        return NULL;
    }
    stat(file_path, &file);
    return get_output(fd, file.st_size);
}

char **get_config(void)
{
    char *config = NULL;
    DIR *dir = opendir(CONFIG_DIR);
    struct dirent *file = readdir(dir);

    while (file) {
        if (config && file->d_name[0] != '.') {
            config = my_strcat(config, get_new_file(file->d_name));
        }
        if (!config && file->d_name[0] != '.') {
            config = get_new_file(file->d_name);
        }
        file = readdir(dir);
    }
    return my_str_to_word_array(config, "\n");
}
