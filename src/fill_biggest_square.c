/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** Fill with 'x' the square
*/

#include <my.h>
#include <bsq.h>

static void first_matching(map_t *map, int square_size, int *x, int *y)
{
    while (*y < map->nb_lines) {
        while (*x < map->nb_columns) {
            if (map->surface[*y][*x] == square_size)
                return;
            *x += 1;
        }
        *x = 0;
        *y += 1;
    }
}

void fill_biggest_square(char *buffer, map_t *map, int square_size)
{
    int index = 0;
    int i = 0;
    int j = 0;
    int x = 0;
    int y = 0;

    first_matching(map, square_size, &x, &y);
    while (j < square_size) {
        while (i < square_size) {
            index = ((map->nb_columns + 1) * (y + j)) + (x + i);
            buffer[index] = 'x';
            i += 1;
        }
        i = 0;
        j += 1;
    }
}
