/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** Functions to find the biggest square
*/

#include <my.h>
#include <bsq.h>

static int check_no_obstacle(int size, int **map, int x, int y)
{
    int i = 0;
    int j = 0;

    while (j < size) {
        while (i < size) {
            if (map[y + j][x + i] == 0)
                return (1);
            i += 1;
        }
        i = 0;
        j += 1;
    }
    return (0);
}

static void try_to_find_square(int size, map_t *map, int x, int y)
{
    int i = 0;
    int j = 0;

    if (x + size - 1 >= map->nb_columns || y + size - 1 >= map->nb_lines)
        return;
    if (check_no_obstacle(size, map->surface, x, y) == 1)
        return;
    while (j < size) {
        while (i < size) {
            map->surface[y + j][x + i] = size;
            i += 1;
        }
        i = 0;
        j += 1;
    }
}

void try_square_of_size(int size, map_t *map)
{
    int x = 0;
    int y = 0;

    while (y < map->nb_lines) {
        while (x < map->nb_columns) {
            try_to_find_square(size, map, x, y);
            x += 1;
        }
        x = 0;
        y += 1;
    }
}

int biggest_nb(map_t *map)
{
    int x = 0;
    int y = 0;
    int value = 0;
    int max = 0;

    while (y < map->nb_lines) {
        while (x < map->nb_columns) {
            value = map->surface[y][x];
            max = (value > max) ? value : max;
            x += 1;
        }
        x = 0;
        y += 1;
    }
    return (max);
}
