/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** Free the allocated buffer
*/

#include <my.h>
#include <bsq.h>

void free_buffer(buffer_t **buffer)
{
    free((*buffer)->string);
    free(*buffer);
    *buffer = NULL;
}
