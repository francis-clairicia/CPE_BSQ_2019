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
    if (ac != 2)
        return (84);
    return (bsq(av[1]));
}
