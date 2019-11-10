/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** Find the Biggest Square
*/

#include <my.h>
#include <bsq.h>

static int read_buffer(char const *filepath,  char **buffer)
{
    int fd = 0;
    int size = 0;
    struct stat statbuf;

    if (stat(filepath, &statbuf) == -1)
        return (-1);
    size = statbuf.st_size;
    *buffer = malloc(sizeof(char) * (size + 1));
    fd = open(filepath, O_RDONLY);
    size = read(fd, *buffer, size);
    (*buffer)[size] = 0;
    close(fd);
    return (size);
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
    int buffer_size = 0;

    buffer_size = read_buffer(filepath, &buffer);
    if (buffer_size == -1 || check_error(buffer))
        return (84);
    nb_lines = get_number_of_lines(&buffer);
    nb_columns = my_find_char(buffer, '\n');
    find_the_biggest_square(buffer, nb_lines, nb_columns);
    write(1, buffer, buffer_size);
    free(buffer);
    return (0);
}
