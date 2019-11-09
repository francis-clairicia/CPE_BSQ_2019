/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** Header for BSQ project
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#ifndef HEADER_BSQ
#define HEADER_BSQ

typedef struct s_map
{
    int nb_lines;
    int nb_columns;
    int **surface;
} map_t;

int bsq(char const *filepath);
void find_the_biggest_square(char *buffer, int nb_lines, int nb_columns);

int check_error(char const *buffer);
void try_square_of_size(int size, map_t *map);
int biggest_nb(map_t *map);
void fill_biggest_square(char *buffer, map_t *map, int square_size);

#endif
