/*
** EPITECH PROJECT, 2023
** src/main
** File description:
** main test
*/

#include "../include/particle.h"
#include "../include/test.h"

#include <stdio.h>
#include <stdlib.h>

void event_manager(sfRenderWindow *window)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed || (event.type == sfEvtKeyPressed &&
        event.key.code == sfKeyEscape))
            sfRenderWindow_close(window);
    }
}

void render_manager(anim_list_t *anims, double dt)
{
    for (; anims != NULL; anims = anims->next)
        anim_render(anims->anim, dt);
}

void draw_manager(sfRenderWindow *window, anim_list_t *anims)
{
    sfRenderWindow_clear(window, sfBlack);
    for (; anims != NULL; anims = anims->next) {
        printf("in draw_manager %f\n", anims->anim->duration);
        anim_display(window, anims->anim);
    }
    sfRenderWindow_display(window);
}

void render_game(sfRenderWindow *window, sfClock *game_clock,
anim_list_t *anims)
{
    double prev_frame_time = sfClock_getElapsedTime(game_clock).microseconds;
    double dt;

    while (sfRenderWindow_isOpen(window)) {
        dt = get_delta_time(game_clock, &prev_frame_time);
        printf("dt: %f\n", dt);

        event_manager(window);

        render_manager(anims, dt);

        draw_manager(window, anims);
    }
}

int main(void)
{
    sfVideoMode video_mode = { WIDTH, HEIGHT, 32 };
    sfRenderWindow *window = sfRenderWindow_create(video_mode, "SFML window",
    sfClose | sfResize, NULL);
    sfClock *game_clock = sfClock_create();
    anim_list_t *anims = create_test_anims();

    if (!window)
        return 84;

    sfRenderWindow_setFramerateLimit(window, FPS);

    render_game(window, game_clock, anims);

    sfRenderWindow_destroy(window);
    sfClock_destroy(game_clock);
    free_anims(anims);
    return 0;
}
