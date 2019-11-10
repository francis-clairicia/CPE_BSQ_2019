/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** Find the biggest square
*/

#include <my.h>
#include <bsq.h>

int buffer_index(map_t *map, int x, int y)
{
    return (((map->nb_columns + 1) * y) + x);
}

static void fill_square(map_t *map, square_t *square)
{
    int i = 0;
    int j = 0;

    while (j < square->size) {
        while (i < square->size) {
            map->buffer[buffer_index(map, square->x + i, square->y + j)] = 'x';
            i += 1;
        }
        i = 0;
        j += 1;
    }
}

void find_the_biggest_square(char *buffer, int nb_lines, int nb_columns)
{
    map_t map = {nb_lines, nb_columns, buffer};
    square_t square = {0, 0, 0};
    int bsq_found = 0;
    int bsq_size = 0;

    while (bsq_found == 0) {
        try_square_of_greater_size(&square, &map);
        if (square.size > bsq_size)
            bsq_size += 1;
        else
            bsq_found = 1;
    }
    fill_square(&map, &square);
}
