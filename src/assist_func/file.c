/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** Functions related to file handling
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "rpg.h"

int get_file_size(char const *filename)
{
    int fd = open(filename, S_IRUSR);
    unsigned int size = 0;
    int char_read = 0;
    char buffer[BUFSIZ];

    if (fd == SYS_ERROR)
        return OPEN_ERROR;
    do {
        size += char_read;
        char_read = read(fd, buffer, BUFSIZ - 1);
    } while (char_read != -1 && char_read != 0);
    close(fd);
    return size;
}

int open_append(char const *filename)
{
    int fd = open(filename, O_RDWR | O_APPEND | O_CREAT, 0644);

    if (fd == SYS_ERROR) {
        return ERROR;
    }
    return fd;
}

int read_open(char const *filename)
{
    int fd = open(filename, O_RDONLY);

    if (fd == SYS_ERROR) {
        return OPEN_ERROR;
    }
    return fd;
}

char *get_file_content(char const *filename)
{
    int fd = read_open(filename);
    char *buffer = NULL;
    int char_read = 0;

    if (fd == OPEN_ERROR) {
        return NULL;
    }
    buffer = malloc(sizeof(char) * (get_file_size(filename) + 1));
    if (buffer == NULL) {
        return NULL;
    }
    char_read = read(fd, buffer, get_file_size(filename));
    buffer[char_read] = '\0';
    return buffer;
}
