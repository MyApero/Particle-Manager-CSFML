/*
** EPITECH PROJECT, 2023
** src/main
** File description:
** main test
*/

#include "../include/particle.h"

particle_t *init_particle(void)
{
    
}

void event_manager(void)
{

}

void draw_manager(particle_t *particle)
{

}

void upadate_manager(particle_t *particle)
{

}

int main(void)
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow* window;
    /* Create the main window */
    window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
    if (!window)
        return 84;
    while (sfRenderWindow_isOpen(window)) {
        /* Process events */
        sfEvent event;
        while (sfRenderWindow_pollEvent(window, &event)) {
            /* Close window : exit */
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        /* Clear the screen */
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_display(window);
    }
    /* Cleanup resources */
    sfRenderWindow_destroy(window);
    return 0;
}
