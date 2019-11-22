/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** window_square.c
*/

#include "my.h"
#include "bsq.h"
#include "csfml.h"

static sfVector2u get_square_size(char const *map)
{
    sfVector2u square_size = {0, 0};
    int line;

    while (map[0] != '\0') {
        line = my_find_char(map, '\n');
        square_size.y += 1;
        square_size.x = line;
        map = &map[line + 1];
    }
    return (square_size);
}

static void draw_map(framebuffer_t *fb, char object,
    sfVector2u pos, int show_square)
{
    if (object == 'x' && show_square == 1)
        put_pixel(fb, pos.x, pos.y, sfColor_fromRGB(170, 170, 170));
    else if (object == 'o')
        put_pixel(fb, pos.x, pos.y, sfColor_fromRGB(0, 130, 0));
    else
        put_pixel(fb, pos.x, pos.y, sfGreen);
}

framebuffer_t *get_map(char const *buffer, int show_square)
{
    sfVector2u sq_size = get_square_size(buffer);
    framebuffer_t *fb = framebuffer_create(sq_size.x, sq_size.y);
    int i = 0;
    sfVector2u pos = {0, 0};

    while (buffer[i] != '\0') {
        draw_map(fb, buffer[i], pos, show_square);
        i += 1;
        if (buffer[i] == '\n') {
            i += 1;
            pos.x = 0;
            pos.y += 1;
        } else
            pos.x += 1;
    }
    return (fb);
}

static void resize_framebuffer(framebuffer_t *fb, float width, float height)
{
    float scale_value = 1;
    sfVector2f scale;
    sfVector2u size;

    framebuffer_update(fb);
    size = sfTexture_getSize(fb->texture);
    if (size.x >= size.y)
        scale_value = width / (float)size.x;
    else
        scale_value = height / (float)size.y;
    scale.x = scale_value;
    scale.y = scale_value;
    sfSprite_setScale(fb->sprite, scale);
}

void place_framebuffer(framebuffer_t *fb, sfIntRect rect)
{
    sfVector2u size;
    sfVector2f origin;
    sfVector2f position;

    resize_framebuffer(fb, rect.width, rect.height);
    size = sfTexture_getSize(sfSprite_getTexture(fb->sprite));
    origin.x = size.x / 2;
    origin.y = size.y / 2;
    sfSprite_setOrigin(fb->sprite, origin);
    position.x = rect.left;
    position.y = rect.top;
    sfSprite_setPosition(fb->sprite, position);
}