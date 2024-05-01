/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** Function to get len of a char **array
*/

#include <stddef.h>

unsigned int my_strstrlen(char **array)
{
    unsigned int size = 0;

    if (array == NULL) {
	return 0;
    }
    while (array[size] != NULL) {
	size++;
    }
    return size;
}
