/*
** EPITECH PROJECT, 2023
** src/main
** File description:
** main test
*/

#include "../include/user.h"

#include <stdio.h>
#include <stdlib.h>

static int get_particles_number(anim_t *anims)
{
    int i = 0;
    anim_t *anim = anims;
    particles_t *particles;

    if (anim == NULL)
        return 0;
    for (; anim != NULL; anim = anim->next) {
        particles = anim->particles;
        for (; particles != NULL; particles = particles->next)
            i++;
    }
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
        printf("Number of Particles: %d\n", get_particles_number(*anims));
    }
}

int main(void)
{
    sfVideoMode video_mode = {WIDTH, HEIGHT, 32};
    sfRenderWindow *window = sfRenderWindow_create(video_mode, "SFML window",
    sfClose | sfResize, NULL);
    sfClock *game_clock = sfClock_create();
    anim_t *anims = create_anim_rain();

    if (!window)
        return 84;

    sfRenderWindow_setFramerateLimit(window, 60);

    execute(window, game_clock, &anims);

    sfRenderWindow_destroy(window);
    sfClock_destroy(game_clock);
    free_anims(anims);
    return 0;
}
