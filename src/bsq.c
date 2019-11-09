/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** Find the Biggest Square
*/

#include <my.h>
#include <bsq.h>

static char *read_buffer(char const *filepath)
{
    int fd = 0;
    int size = 0;
    char *buffer = NULL;
    struct stat statbuf;

    if (stat(filepath, &statbuf) == -1)
        return (NULL);
    size = statbuf.st_size;
    buffer = malloc(sizeof(char) * (size + 1));
    fd = open(filepath, O_RDONLY);
    size = read(fd, buffer, size);
    buffer[size] = 0;
    close(fd);
    return (buffer);
}

static int get_number_of_lines(char **buffer)
{
    char *new_buffer = NULL;
    int nb_lines = my_getnbr(*buffer);

    new_buffer = my_strdup(&(*buffer)[my_find_char(*buffer, '\n') + 1]);
    free(*buffer);
    *buffer = new_buffer;
    return (nb_lines);
}

int bsq(char const *filepath)
{
    int nb_lines = 0;
    int nb_columns = 0;
    char *buffer = NULL;

    buffer = read_buffer(filepath);
    if (check_error(buffer))
        return (84);
    nb_lines = get_number_of_lines(&buffer);
    nb_columns = my_find_char(buffer, '\n');
    find_the_biggest_square(buffer, nb_lines, nb_columns);
    write(1, buffer, my_strlen(buffer));
    free(buffer);
    return (0);
}
