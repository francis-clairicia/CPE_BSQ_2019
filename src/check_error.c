/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** BSQ Handling errors
*/

#include <my.h>
#include <bsq.h>

static char *get_first_line(char const *buffer)
{
    char *first_line = NULL;
    int size_line = my_find_char(buffer, '\n');

    if (size_line == -1)
        return (NULL);
    first_line = malloc(sizeof(char) * (size_line + 1));
    my_strncpy(first_line, buffer, size_line);
    return (first_line);
}

static int only_valid_chars(char const *buffer)
{
    int i = 0;
    char valid_chars[] = "0123456789.o\n";

    while (buffer[i] != '\0') {
        if (my_find_char(valid_chars, buffer[i]) == -1)
            return (1);
        i += 1;
    }
    return (0);
}

static int check_map(char const *buffer, int total_nb_lines)
{
    int i = 0;
    int nb_lines = 0;
    int nb_columns = 0;
    int total_nb_columns = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == '\n') {
            if (nb_lines == 1)
                total_nb_columns = nb_columns;
            if (nb_lines > 0 && nb_columns != total_nb_columns)
                return (1);
            nb_lines += 1;
            nb_columns = 0;
        } else
            nb_columns += 1;
        i += 1;
    }
    if (nb_lines - 1 != total_nb_lines)
        return (1);
    return (0);
}

int check_error(char const *buffer)
{
    int nb_lines = 0;
    char *first_line = get_first_line(buffer);

    if (first_line == NULL)
        return (1);
    if (my_str_isnum(first_line) == 0) {
        free(first_line);
        return (1);
    }
    nb_lines = my_getnbr(first_line);
    free(first_line);
    if (only_valid_chars(buffer))
        return (1);
    return (check_map(buffer, nb_lines));
}
