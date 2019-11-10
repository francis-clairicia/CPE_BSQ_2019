/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** Functions to find the biggest square
*/

#include <my.h>
#include <bsq.h>

static int check_no_obstacle(int size, map_t *map, int x, int y)
{
    int i = 0;
    int j = 0;

    while (j < size) {
        if (map->buffer[buffer_index(map, x + i, y + j)] == 'o')
            return (1);
        i += 1;
        if (i == size) {
            i = 0;
            j += 1;
        }
    }
    return (0);
}

static int try_to_find_square(int size, map_t *map, int x, int y)
{
    if (x + size - 1 >= map->nb_columns || y + size - 1 >= map->nb_lines)
        return (0);
    if (check_no_obstacle(size, map, x, y) == 1)
        return (0);
    return (1);
}

void try_square_of_greater_size(square_t *square, map_t *map)
{
    int x = square->x;
    int y = square->y;

    while (y < map->nb_lines) {
        if (try_to_find_square(square->size + 1, map, x, y) == 1) {
            square->size += 1;
            square->x = x;
            square->y = y;
            return;
        }
        x += 1;
        if (x == map->nb_columns) {
            x = 0;
            y += 1;
        }
    }
}
