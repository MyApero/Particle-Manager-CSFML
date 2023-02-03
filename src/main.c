/*
** EPITECH PROJECT, 2023
** src/main
** File description:
** main test
*/

#include "../include/particle.h"

particles_t *init_particle(void)
{
    
}

void event_manager(sfRenderWindow *window)
{
     sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}

void draw_manager(particles_t *particle)
{

}

void upadate_manager(particles_t *particle)
{

}



void render_game()
{

}

int main(void)
{
    game_t *game = malloc(sizeof(game_t));

    initialize_game(game);

    render_game(game);

    big_free(g);

    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow *window;
    window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
    if (!window)
        return 84;
    while (sfRenderWindow_isOpen(window)) {
        event_manager(window);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    return 0;
}
