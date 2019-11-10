/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** Find the Biggest Square
*/

#include <my.h>
#include <bsq.h>

buffer_t *read_buffer(char const *filepath)
{
    int fd = 0;
    int size = 0;
    buffer_t *buffer = malloc(sizeof(buffer_t));
    struct stat statbuf;

    buffer->string = NULL;
    if (stat(filepath, &statbuf) == -1)
        return (buffer);
    size = statbuf.st_size;
    buffer->string = malloc(sizeof(char) * (size + 1));
    fd = open(filepath, O_RDONLY);
    buffer->size = read(fd, buffer->string, size);
    (buffer->string)[buffer->size] = 0;
    close(fd);
    return (buffer);
}

static int get_number_of_lines(buffer_t *buffer)
{
    char *current_buf = buffer->string;
    char *new_buffer = NULL;
    int nb_lines = my_getnbr(buffer->string);

    new_buffer = my_strdup(&current_buf[my_find_char(current_buf, '\n') + 1]);
    free(buffer->string);
    buffer->string = new_buffer;
    buffer->size = my_strlen(new_buffer);
    return (nb_lines);
}

buffer_t *bsq(char const *filepath)
{
    int nb_lines = 0;
    int nb_columns = 0;
    buffer_t *buffer = read_buffer(filepath);

    if (check_error(buffer->string))
        return (NULL);
    nb_lines = get_number_of_lines(buffer);
    nb_columns = my_find_char(buffer->string, '\n');
    find_the_biggest_square(buffer->string, nb_lines, nb_columns);
    return (buffer);
}
