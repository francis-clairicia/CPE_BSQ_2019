/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** Find the Biggest Square
*/

#include <my.h>
#include <bsq.h>

int main(int ac, char **av)
{
    buffer_t *buffer = NULL;

    if (ac != 2)
        return (84);
    buffer = bsq(av[1]);
    if (buffer == NULL)
        return (84);
    if (buffer->string == NULL)
        return (84);
    show_square(buffer);
    free_buffer(&buffer);
    return (0);
}
