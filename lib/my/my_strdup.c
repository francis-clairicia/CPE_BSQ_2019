/*
** EPITECH PROJECT, 2019
** My strdup()
** File description:
** Reproduce strdup() function
*/

#include <my.h>

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *dest;

    if (len < 0)
        return (NULL);
    dest = malloc(sizeof(char) * (len + 1));
    if (dest == NULL)
        return (NULL);
    my_strcpy(dest, src);
    return (dest);
}
