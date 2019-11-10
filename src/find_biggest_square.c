/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** Find the biggest square
*/

#include <my.h>
#include <bsq.h>

static void fill_square(char *buffer, int nb_columns, square_t *square)
{
    int index = 0;
    int i = 0;
    int j = 0;

    while (j < square->size) {
        while (i < square->size) {
            index = (nb_columns * (square->y + j)) + (square->x + i);
            buffer[index] = 'x';
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
    fill_square(buffer, map.nb_columns + 1, &square);
}
