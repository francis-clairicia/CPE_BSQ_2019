/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** Fill with 'x' the square
*/

#include <my.h>
#include <bsq.h>

void fill_biggest_square(char *buffer, int nb_columns, square_t *square)
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
