/*
** EPITECH PROJECT, 2023
** src/main
** File description:
** main test
*/

#include "../include/user.h"

#include <stdio.h>
#include <stdlib.h>

static int get_particles_number(particles_t *particles)
{
    int i = 0;
    for (; particles != NULL; particles = particles->next)
        i++;
    return i;
}

void execute(sfRenderWindow *window, sfClock *game_clock,
anim_t **anims)
{
    double prev_frame_time = sfClock_getElapsedTime(game_clock).microseconds;
    double dt;

    while (sfRenderWindow_isOpen(window)) {
        dt = get_delta_time(game_clock, &prev_frame_time);
        event_manager(window, anims);
        update_manager(anims, dt);
        draw_manager(window, *anims);
    }
}

int main(void)
{
    sfVideoMode video_mode = { WIDTH, HEIGHT, 32 };
    sfRenderWindow *window = sfRenderWindow_create(video_mode, "SFML window",
    sfClose | sfResize, NULL);
    sfClock *game_clock = sfClock_create();
    anim_t *anims = create_first_anim();

    if (!window)
        return 84;

    sfRenderWindow_setFramerateLimit(window, 60);

    execute(window, game_clock, &anims);

    sfRenderWindow_destroy(window);
    sfClock_destroy(game_clock);
    free_anims(anims);
    return 0;
}
