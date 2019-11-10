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
    int value_to_return = 0;

    if (ac != 2)
        return (84);
    buffer = bsq(av[1]);
    if (buffer->string == NULL)
        value_to_return = 84;
    if (value_to_return == 0)
        write(1, buffer->string, buffer->size);
    free_buffer(&buffer);
    return (value_to_return);
}
