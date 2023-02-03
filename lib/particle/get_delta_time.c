/*
** EPITECH PROJECT, 2022
** get_delta_t
** File description:
** gets delta t
*/

void get_delta_time(game_t *g)
{
    sfInt64 now = sfClock_getElapsedTime(g->game_clock).microseconds;
    g->dt = (now - g->prev_frame_time) / 1000000.0 * GAME_TICK;
    g->prev_frame_time = now;
}
