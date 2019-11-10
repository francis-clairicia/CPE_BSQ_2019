/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** Find the biggest square
*/

#include <my.h>
#include <bsq.h>

static void get_map(map_t *map, char *buffer)
{
    int i = 0;
    int x = 0;
    int y = 0;

    map->surface = malloc(sizeof(char *) * (map->nb_lines));
    while (buffer[i] != '\0') {
        map->surface[y] = malloc(sizeof(char) * (map->nb_columns));
        while (buffer[i] != '\0' && buffer[i] != '\n') {
            map->surface[y][x] = buffer[i];
            x += 1;
            i += 1;
        }
        x = 0;
        y += 1;
        i += 1;
    }
}

static void free_map(map_t *map)
{
    int i = 0;

    while (i < map->nb_lines) {
        free(map->surface[i]);
        i += 1;
    }
    free(map->surface);
}

void find_the_biggest_square(char *buffer, int nb_lines, int nb_columns)
{
    map_t map = {nb_lines, nb_columns, NULL};
    square_t square = {0, 0, 0};
    int bsq_found = 0;
    int bsq_size = 0;

    get_map(&map, buffer);
    while (bsq_found == 0) {
        try_square_of_greater_size(&square, &map);
        if (square.size > bsq_size)
            bsq_size += 1;
        else
            bsq_found = 1;
    }
    fill_biggest_square(buffer, map.nb_columns + 1, &square);
    free_map(&map);
}
