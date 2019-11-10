/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** BSQ Handling errors
*/

#include <my.h>
#include <bsq.h>

static int valid_first_line(char const *buffer)
{
    int size_line = my_find_char(buffer, '\n');
    int i = 0;

    if (size_line == -1)
        return (0);
    while (buffer[i] != '\n') {
        if (buffer[i] < '0' || buffer[i] > '9')
            return (0);
        i += 1;
    }
    return (1);
}

static int only_valid_chars(char const *buffer)
{
    int i = 0;
    char valid_chars[] = ".o\n";

    while (buffer[i] != '\0') {
        if (my_find_char(valid_chars, buffer[i]) == -1)
            return (0);
        i += 1;
    }
    return (1);
}

static int check_map(char const *buffer, int total_nb_lines)
{
    int i = 0;
    int nb_lines = 0;
    int nb_columns = 0;
    int total_nb_columns = my_find_char(buffer, '\n');

    while (buffer[i] != '\0') {
        if (buffer[i] != '\n') {
            nb_columns += 1;
        } else if (nb_columns != total_nb_columns) {
            return (1);
        } else {
            nb_lines += 1;
            nb_columns = 0;
        }
        i += 1;
    }
    if (nb_lines != total_nb_lines)
        return (1);
    return (0);
}

int check_error(char const *buffer)
{
    char const *map;

    if (valid_first_line(buffer) == 0)
        return (1);
    map = &buffer[my_find_char(buffer, '\n') + 1];
    if (only_valid_chars(map) == 0)
        return (1);
    return (check_map(map, my_getnbr(buffer)));
}
