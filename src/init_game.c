/*
** EPITECH PROJECT, 2022
** initialize_game
** File description:
** initialize_game
*/

#include ""

sfRenderWindow *create_window(void)
{
    sfVideoMode video_mode = { WIDTH, HEIGHT, 32 };
    sfRenderWindow *window = sfRenderWindow_create(video_mode, "Image",
    sfClose | sfResize, NULL);
    return window;
}

void initialize_game(game_t *g)
{
    g->wd = create_window();
    g->in_menu = sfTrue;
    g->game_clock = sfClock_create();
    g->prev_frame_time = sfClock_getElapsedTime(g->game_clock).microseconds;

    sfRenderWindow_setFramerateLimit(g->wd, FPS);
}
