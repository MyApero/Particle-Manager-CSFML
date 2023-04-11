/*
** EPITECH PROJECT, 2023
** src/main
** File description:
** main test
*/

#include "user.h"

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

    sfSprite *capy = sfSprite_create();
    sfTexture *capt_txr = sfTexture_createFromFile(CAPY_PATH, NULL);
    sfSprite_setTexture(capy, capt_txr, false);
    anim_props_t *anims_props = create_anims_props_list();
    append_anim_props(&anims_props, create_anim_props_capy(capy, capt_txr));
    sfRenderWindow_setMouseCursorVisible(window, false);

    while (sfRenderWindow_isOpen(window)) {
        dt = get_delta_time(game_clock, &prev_frame_time);
        event_manager(window, anims, capy, anims_props);
        update_manager(anims, dt, window, capy);
        draw_manager(window, *anims, capy);
        // printf("Number of Particles: %d\n", get_particles_number(*anims));
    }
    destroy_anims_props(anims_props);
    sfTexture_destroy(capt_txr);
    sfSprite_destroy(capy);
}

int main(void)
{
    sfVideoMode video_mode = {WIDTH, HEIGHT, 32};
    sfRenderWindow *window = sfRenderWindow_create(video_mode, "SFML window",
    sfClose | sfResize, NULL);
    sfClock *game_clock = sfClock_create();
    anim_t *anims = NULL;

    if (!window)
        return 84;

    sfRenderWindow_setFramerateLimit(window, 60);

    execute(window, game_clock, &anims);

    sfRenderWindow_destroy(window);
    sfClock_destroy(game_clock);
    free_anims(anims);
    return 0;
}
