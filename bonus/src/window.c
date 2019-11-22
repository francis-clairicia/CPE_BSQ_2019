/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** window.h
*/

#include "my.h"
#include "bsq.h"
#include "csfml.h"

static void draw_maps(sfRenderWindow *window,
    sfSprite *map_before, sfSprite *map_after)
{
    sfRenderWindow_clear(window, sfColor_fromRGB(0, 255, 255));
    sfRenderWindow_drawSprite(window, map_before, NULL);
    sfRenderWindow_drawSprite(window, map_after, NULL);
    sfRenderWindow_display(window);
}

void show_square(buffer_t *buffer)
{
    sfRenderWindow *window = create_window("2D Stadia", 1280, 720);
    framebuffer_t *map_before = get_map(buffer->string, 0);
    framebuffer_t *map_after = get_map(buffer->string, 1);
    sfIntRect map_before_rect = {325, 360, 620, 700};
    sfIntRect map_after_rect = {955, 360, 620, 700};
    sfEvent event;

    place_framebuffer(map_before, map_before_rect);
    place_framebuffer(map_after, map_after_rect);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        draw_maps(window, map_before->sprite, map_after->sprite);
    }
    framebuffer_destroy(map_before);
    framebuffer_destroy(map_after);
    sfRenderWindow_destroy(window);
}